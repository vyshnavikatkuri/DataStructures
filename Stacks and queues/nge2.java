package Stacks and queues;
import java.util.*;
public class nge2 {
    
}
class Solution {
    public int[] nextGreaterElements(int[] nums) {
        int n=nums.length;
        int arr[]=new int[n];
        Arrays.fill(arr,-1);
        Stack<Integer>st=new Stack<>();
        int j=2*n-1;
        while(j>=0){
            while(!st.isEmpty() && nums[j%n]>=st.peek()){st.pop();}
            if(!st.isEmpty()){
                arr[j%n]=st.peek();
            }
            st.push(nums[j%n]);
            j--;
        }
        return arr;
    }
}
