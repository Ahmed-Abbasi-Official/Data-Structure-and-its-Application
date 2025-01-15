
public class SelectionSort {
    // Selection Sort Method
    public SelectionSort(int[] arr) {
        for (int i = 0; i < arr.length - 1; i++) { // 4
            int smallestNum = i;    // 4
            for (int j = i + 1; j < arr.length; j++) {
                // 1
                if (arr[smallestNum] > arr[j]) {
                    smallestNum = j; // 1
                    int temp = arr[smallestNum];  // 1
                    arr[smallestNum] = arr[i]; //  4
                    arr[i] = temp; // 1
                }
            }

        }
    }
}
