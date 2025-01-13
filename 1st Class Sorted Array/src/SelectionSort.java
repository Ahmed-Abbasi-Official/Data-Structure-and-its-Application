
public class SelectionSort {

    // SELECTION SORTING METHOD ;
    
    public SelectionSort(int[] arr) {
        for (int i = 0; i < arr.length - 1; i++) {
            int smallestNum = i;
            for (int j = i + 1; j < arr.length; j++) {
                if (arr[smallestNum] > arr[j]) {
                    smallestNum = j;
                    int temp = arr[smallestNum];
                    arr[smallestNum] = arr[i];
                    arr[i] = temp;
                }
            }

        }
    }
}
