public class CountNegativeElements {

    /**
     * Count negative elements
     *
     * @param arr array to search
     * @return count of negative elements in arr
     * @ throws NullPointerException if arr is null
     */
    public int countNegative (int [] arr)
    {
        int count = 0;
        for (int i=0; i < arr.length; i++)
        {
            if (arr[i] < 0)
            {
                count++;
            }
        }
        return count;
    }
}
// test: arr = [4, -5, 0, -5]; Expected = 2