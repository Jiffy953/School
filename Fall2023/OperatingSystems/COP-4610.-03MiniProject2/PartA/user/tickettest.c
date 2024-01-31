#include "types.h"
#include "user.h"
#include "pstat.h"

#define CHILDREN 5

int main(void) {
    int pid;
    struct pstat st;

    // Create CHILDREN processes
    for (int i = 0; i < CHILDREN; i++) {
        pid = fork();
        if (pid == 0) {
            // Child process: assign tickets and then busy-wait
            settickets(10 * (i + 1));
            for(;;) {
                // Busy-wait loop.
            }
        }
    }

    // Parent process continues here.
    if (pid > 0) {
        // Give some time for the children to run
        sleep(100);

        // Now collect and print the pstat information
        if (getpinfo(&st) != 0) {
            printf(2, "Error: getpinfo call failed\n");
            exit();
        }

        // Print the pstat information
        printf(1, "pid,tickets,ticks\n");
        for (int i = 0; i < NPROC; i++) {
            if (st.inuse[i]) {
                printf(1, "%d,%d,%d\n", st.pid[i], st.tickets[i], st.ticks[i]);
            }
        }

        // Kill all children after collecting data
        for (int i = 0; i < CHILDREN; i++) {
            wait();
        }
    }

    exit();
}
