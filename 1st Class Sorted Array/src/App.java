public class App {
    public static void main(String[] args) {

        int arr[] = {4,1,5,2,3};   
        // SELECTION SORT OBJECT ;
        // SelectionSort ObjSc=new SelectionSort(arr);
        // Bubble SORT OBJECT ;
        BubbleSort ObjBs=new BubbleSort(arr);




        // PRINTED SORTED ARRAY ;

        System.out.print("Sorted Array: ");
        for (int num : arr) {
            System.out.print(num + " ");
        }
    }

    
}
