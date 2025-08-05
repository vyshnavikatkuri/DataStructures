package Sorting;

public class Bubblesort {
    public void bubbleSort(int[] arr) {
        // code here
        int n=arr.length;
        boolean swapped=false;
        for(int i=0;i<n-1;i++){
            for(int j=0;j<n-i-1;j++){
                if(arr[j]>arr[j+1]){
                    swapped=true;
                    int temp=arr[j];
                    arr[j]=arr[j+1];
                    arr[j+1]=temp;
                }
            }
            if(!swapped) break;
        }
    }
}
//o(n^2)-tc,bestcase=o(n)
//o(1)-sc
//inplace,stable algo
