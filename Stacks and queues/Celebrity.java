package Stacks and queues;
import java.util.*;
public class Solution {
    public int celebrity(int mat[][]) {
        // code here
        Stack<Integer>st=new Stack<>();
        for(int i=0;i<mat.length;i++){
            st.push(i);
        }
        while(st.size()>1){
            int i=st.peek();st.pop();
            int j=st.peek();st.pop();
            if(mat[i][j]==0){
                st.push(i);
            }else{
                st.push(j);
            }
        }
        int celeb=st.peek();
        for(int i=0;i<mat.length;i++){
            if(i!=celeb &&(mat[i][celeb]==0 || mat[celeb][i]==1)) return -1;
        }
        return celeb;
    }
} 
