package sorting;

public class Quicksort {
    public void quickSort(int[] arr, int low, int high) {
        // code here
        if(low<high){
            int pivot=partition(arr,low,high);
            quickSort(arr,low,pivot-1);
            quickSort(arr,pivot+1,high);
        }
    }

    private int partition(int[] arr, int low, int high) {
        // code here
        int pivot=arr[low];
        int i=low+1,j=high;
        while(i<=j){
            while(i<=high && arr[i]<=pivot){
                i++;
            }
            while(j>=0 && arr[j]>pivot){
                j--;
            }
            if(i<j){
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
        int temp=arr[j];
        arr[j]=pivot;
        arr[low]=temp;
        return j;
        
    }
}
//It’s a divide-and-conquer algorithm.
//o(nlogn)-bestcase and avg case
//| Case         | Depth of Recursion (log n / n) | Work per Level (O(n)) | Total Time Complexity |
// | ------------ | ------------------------------ | --------------------- | --------------------- |
// | Best Case    | log n                          | O(n)                  | O(n log n)            |
// | Average Case | log n                          | O(n)                  | O(n log n)            |
// | Worst Case   | n                              | O(n)                  | O(n²)                 |
//  In contrast, Worst Case:
// If pivot is always the smallest/largest:

// Example: [1, 2, 3, 4, 5] → pivot = 1

// One side is always empty, other is size n-1.

// So, number of levels = n

// Total work = O(n²)
