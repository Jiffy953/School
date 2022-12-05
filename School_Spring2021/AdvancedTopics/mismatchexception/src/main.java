import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int x;
        while(true)
        {
            System.out.print("Enter number: ");
            try
            {
                x = input.nextInt();
                break;
            }
            catch(InputMismatchException e)
            {
                input.next();
                continue;
            }
        }
    }
}