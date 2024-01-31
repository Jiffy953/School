//I know this is broken but I still want to turn in something

import java.util.Scanner;
import java.util.Random;


public class random {
    public static final Scanner CONSOLE = new Scanner(System.in);
    public random(int choice, int upper, int lower, int number)
    {
        guess(choice, upper, lower, number);
    }
    public static void guess(int choice, int upper, int lower, int number) {
        while (choice != number) {
            if (choice != number && upper >= number && lower <= number) {
                if (choice > 50) {
                    upper = choice;
                    System.out.printf("Try again! New bounds are from %d to %d", lower, upper);
                    choice = CONSOLE.nextInt();
                    guess(choice, upper, lower, number);
                } else {
                    lower = choice;
                    System.out.printf("Try again! New bounds are from %d to %d", lower, upper);
                    choice = CONSOLE.nextInt();
                    guess(choice, upper, lower, number);
                }
            }
        }
    }
    public static void main(String args[]) {
        Random rand = new Random(100);
        int number = rand.nextInt();
        int upper = 100;
        int lower = 1;
        System.out.println("Guess a number between 1 and 100");
        int choice = CONSOLE.nextInt();
        random myRandom = new random(choice, upper, lower, number);
    }
}