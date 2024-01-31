import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.assertEquals;

public class CountNegativeElementsTest {

    @Test
    public void testCountNegativeWithNoNegativesOrZeroes() {
        CountNegativeElements counter = new CountNegativeElements();
        int[] arr = {1, 2, 3};
        assertEquals(0, counter.countNegative(arr));
    }

    @Test
    public void testCountNegativeWithNegativesButNoZero() {
        CountNegativeElements counter = new CountNegativeElements();
        int[] arr = {1, -2, 3};
        assertEquals(1, counter.countNegative(arr));
    }

    @Test
    public void testCountNegativeWithErrorStateButNoFailure() {
        CountNegativeElements counter = new CountNegativeElements();
        int[] arr = {1, 2, 0};
        assertEquals(0, counter.countNegative(arr));
    }

    @Test
    public void testCountNegativeGivenCase() {
        CountNegativeElements counter = new CountNegativeElements();
        int[] arr = {4, -5, 0, -5};
        assertEquals(2, counter.countNegative(arr));
    }
}
