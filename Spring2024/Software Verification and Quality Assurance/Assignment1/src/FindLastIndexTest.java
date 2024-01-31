import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.assertEquals;

public class FindLastIndexTest {

    @Test
    public void testFindLastWithoutExecutingFault() {
        FindLastIndex finder = new FindLastIndex();
        int[] x = {1, 2, 3}; // Does not execute the fault
        int y = 3;
        assertEquals(2, finder.findLast(x, y));
    }

    @Test
    public void testFindLastExecutesFaultWithoutError() {
        FindLastIndex finder = new FindLastIndex();
        int[] x = {1, 2, 3, 1}; // Executes the fault but does not result in error
        int y = 1;
        assertEquals(3, finder.findLast(x, y));
    }

    @Test
    public void testFindLastWithElementAtFirstPosition() {
        FindLastIndex finder = new FindLastIndex();
        int[] x = {1, 2, 0};
        int y = 1;
        assertEquals(0, finder.findLast(x, y));
    }

    @Test
    public void testFindLastGivenCase() {
        FindLastIndex finder = new FindLastIndex();
        int[] x = {2, 3, 5}; // Test case provided
        int y = 2;
        assertEquals(0, finder.findLast(x, y));
    }
}
