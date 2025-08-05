package sorting;
public class Selectionsort {
     public void selectionSort(int[] arr) {
        // code here
        int n=arr.length;
        for(int i=0;i<n-1;i++){
            int minind=i;
            for(int j=i+1;j<n;j++){
                if(arr[j]<arr[minind]){
                    minind=j;
                }
            }
            int temp=arr[i];
            arr[i]=arr[minind];
            arr[minind]=temp;
        }
    }
}
//o(n^2)-tc //o(1)-sc //inplace,not stable algo
