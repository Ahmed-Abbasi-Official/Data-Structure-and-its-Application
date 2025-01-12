public class App {
    public static void main(String[] args) throws Exception {
        System.out.println("Hello, World!");

        int arr[]={1,2,4,0};

        int smallestNum=arr[0];

        for(int i=0;i<arr.length;i++){
            if(arr[i]<smallestNum){
                smallestNum=arr[i];
                // Collections.swap(arr, 0, 4);
            }
        }

        System.out.println(smallestNum);


    }
}
