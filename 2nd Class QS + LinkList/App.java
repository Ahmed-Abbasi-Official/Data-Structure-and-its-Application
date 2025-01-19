import java.util.ArrayList;
public class App {
    
    public static void main(String[] args) {











        int num = 4;

        // Quick Sorting
        ArrayList<Integer> arr = new ArrayList<>();
        arr.add(5);
        arr.add(2);
        arr.add(6);
        arr.add(4);
        arr.add(1);
        arr.add(3);

        System.out.println("Before sorting: " + arr);
        QuickSort(arr, 0, arr.size() - 1);
        System.out.println("After sorting: " + arr);
    }

    // QUICK SORT

    public static void QuickSort(ArrayList<Integer> arr, int start, int end) {
        if (start < end) {
            int pivot = partition(arr, start, end); // Partition the array
            QuickSort(arr, start, pivot - 1);      // Sort left side
            QuickSort(arr, pivot + 1, end);       // Sort right side
        }
    }

    public static int partition(ArrayList<Integer> arr, int start, int end) {
        int pivot = arr.get(end); // Choose the last element as the pivot
        int i = start - 1;        // Index of the smaller element

        for (int j = start; j < end; j++) {
            if (arr.get(j) < pivot) {
                i++;
                // Swap arr[i] and arr[j]
                int temp = arr.get(i);
                arr.set(i, arr.get(j));
                arr.set(j, temp);
            }
        }

        // Swap arr[i + 1] and arr[end] (pivot)
        int temp = arr.get(i + 1);
        arr.set(i + 1, arr.get(end));
        arr.set(end, temp);

        return i + 1; // Return the pivot index
    }
}
