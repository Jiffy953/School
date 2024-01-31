import java.util.*;

public class main {
    public static void m(int x) {
        if (x == 1) {
            throw new InputMismatchException("Error 1");
        } else {
            throw new NullPointerException();
        }
    }
    public static void main(String[] args)
    {
        try
        {
            m(1);
        }
        catch(InputMismatchException e)
        {
            System.out.println(e);
        }
    }
}