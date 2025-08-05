package Stacks and queues;

public class StockSpan {
    
}

class Solution {
    public ArrayList<Integer> calculateSpan(int[] arr) {
        // write code here
        int n=arr.length;
        int pge[]=new int[n];
        Arrays.fill(pge,-1);
        Stack<Integer>st=new Stack<>();
        for(int i=0;i<n;i++){
            while(!st.isEmpty() && arr[st.peek()]<=arr[i]){
                st.pop();
            }
            if(!st.isEmpty()) pge[i]=st.peek();
            st.push(i);
        }
        ArrayList<Integer>ans=new ArrayList<>(n);
        for(int i=0;i<n;i++){
            ans.add(i-pge[i]);
        }
        return ans;
    }
}
