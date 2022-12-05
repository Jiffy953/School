import java.util.*;
import java.io.*;

class MyException extends Exception
{
    MyException(String mess)
    {
        super(mess);
    }
}
public class main {
    public static void m(int x) throws IOException, MyException {
        if (x == 1)
        {
            throw new MyException("My Error");
        }
        else
            {
            throw new IOException("IO Error");
            }
    }

    public static void main(String[] args) throws IOException {
            try {
                m(1);
                }
            catch(MyException e)
            {
                System.out.println(e.getMessage());
            }
            catch(IOException e)
            {
                System.out.println(e.getMessage());
            }
            finally
            {
                System.out.println("Exits");
            }
    }
}
