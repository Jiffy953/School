#include "types.h"
#include "user.h"
#include "pstat.h"

#define CHILDREN 5
#define WAIT_LOOP 10000000 // Adjust this value as needed for your system

int main(void) {
    int pid;
    struct pstat st_before, st_after;

    printf(1, "Starting priority test...\n");

    // Set priorities for each child to be created
    int priorities[CHILDREN] = {0, 50, 100, 150, 200};

    // Collect initial stats
    if (getpinfo(&st_before) != 0) {
        printf(2, "Error: getpinfo call failed\n");
        exit();
    }

    // Create child processes with set priorities
    for (int i = 0; i < CHILDREN; i++) {
        pid = fork();
        if (pid == 0) {
            // Child process: assign priority and then busy-wait
            setpriority(priorities[i]);

            // Busy-wait loop for a certain number of iterations
            for (volatile int j = 0; j < WAIT_LOOP; j++);

            // Child process exits after busy-waiting
            exit();
        }
    }

    // Parent process continues here.
    if (pid > 0) {
        // Wait for a while to let the children run and accumulate ticks
        sleep(100); // Extend the sleep time to ensure each child runs

        // Collect stats after the test
        if (getpinfo(&st_after) != 0) {
            printf(2, "Error: getpinfo call failed\n");
            exit();
        }

        // Print the statistics
        printf(1, "PID\tPriority\tTicks\n");
        for (int i = 0; i < NPROC; i++) {
            if (st_after.inuse[i]) {
                printf(1, "%d\t%d\t%d\n",
                       st_after.pid[i],
                       st_after.priority[i],
                       st_after.ticks[i] - st_before.ticks[i]);
            }
        }

        // Kill all children after collecting data
        while(wait() > 0); // Wait for all child processes to finish
    }

    printf(1, "Priority test complete.\n");

    exit();
}
