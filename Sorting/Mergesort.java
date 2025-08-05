package Sorting;

import java.util.ArrayList;
import java.util.List;

public class Mergesort {
 public static void merge(int arr[],int low,int mid,int high){
        int l=low,r=mid+1;
        List<Integer>temp=new ArrayList<>();
        while(l<=mid && r<=high){
            if(arr[l]<arr[r]){
                temp.add(arr[l]);
                l++;
            }else{
                temp.add(arr[r]);
                r++;
            }
        }
        while(l<=mid){
            temp.add(arr[l]);
            l++;
        }
        while(r<=high){
            temp.add(arr[r]);
            r++;
        }
        int j=0;
        for(int i=low;i<=high;i++){
            arr[i]=temp.get(j);
            j++;
        }
        
    }
    void mergeSort(int arr[], int l, int r) {
        // code here
        if(l<r){
            int mid=(l+r)/2;
            mergeSort(arr,l,mid);
            mergeSort(arr,mid+1,r);
            merge(arr,l,mid,r);
        }
    }
}
// Time Complexity: O(n log n)
// Let’s break it into:

// 1. Depth of Recursion Tree = log₂n
// Each recursive call splits the array into two halves.

// For an array of size n, it can be halved log₂n times before reaching size 1 subarrays.

// So, depth = log n

// 2. Work done per level = O(n)
// At each level of the recursion tree, we merge the entire array once.

// Level 0: 1 merge of n elements

// Level 1: 2 merges of n/2 elements → total = n

// Level 2: 4 merges of n/4 elements → total = n

// …

// At every level, total merging = O(n)

// 💡 So:
// Total Time = Depth × Work per level = log n × n = O(n log n)

// 🧠 Space Complexity
// 🔸 Auxiliary Space = O(n)
// During merge, we create temporary arrays to store left and right halves.

// Even though recursion itself uses O(log n) stack space, the extra space for merging dominates.

// 🔸 Total Space:
// With extra merge arrays: O(n)

// Recursive stack space: O(log n)

// So overall space = O(n)

// 👉 Note: Merge Sort is not an in-place algorithm because it uses extra memory for merging.

// 🔁 Summary
// Aspect	Value
// Best Case	O(n log n)
// Average Case	O(n log n)
// Worst Case	O(n log n)
// Space Complexity	O(n)
// Stable	✅ Yes
// In-place	❌ No



