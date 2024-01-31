
import java.util.Scanner;
import java.util.Random;

public class RandomGame {
    public static void main(String args[]) {
        Random rand = new Random();
        int x = rand.nextInt(100);
        System.out.println("Guess a number between 1 and 100: ");
        Scanner console = new Scanner(System.in);
        int y = console.nextInt();
        int upper = 100;
        int lower = 1;
        boolean win = true;

        while (win)
        {
            if (x == y)
            {
                System.out.printf("You win! The number was %d", x);
                win = false;
            }
            else
            {

                if (y > 50 && x <= upper && x <= y)
                {
                    upper = y;
                    System.out.printf("Sorry try again! New bounds are from %d to %d", lower, upper);
                    y = console.nextInt();
                }
                else if (y <= 50 && x >= lower && x >= y)
                {
                    lower = y;
                    System.out.printf("Sorry try again! New bounds are from %d to %d", lower, upper);
                    y = console.nextInt();
                }
                else if (y > upper || y < lower)
                {
                    System.out.println("Number not in range, try again!");
                }
                else
                {
                    System.out.printf("You lose! The number was %d", x);
                    win = false;
                }
            }
        }
    }
}