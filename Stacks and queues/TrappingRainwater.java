package Stacks and queues;

public class TrappingRainwater {
    
}
class Solution {
    public int maxWater(int arr[]) {
        // code here
        int n=arr.length;
        // int lmax[]=new int[n];
        // // Array.fill(lmax,INT_MIN);
        // // Array.fill(rmax,INT_MIN);
        // int rmax[]=new int[n];
        // lmax[0]=arr[0];rmax[n-1]=arr[n-1];
        // for(int i=1;i<n;i++){
        //     lmax[i]=Math.max(lmax[i-1],arr[i]);
        // }
        // for(int i=n-2;i>=0;i--){
        //     rmax[i]=Math.max(rmax[i+1],arr[i]);
        // }
        // int ans=0;
        // for(int i=0;i<n;i++){
        //     ans+=Math.min(lmax[i],rmax[i])-arr[i];
        // }
        // return ans;
        int l=0,r=n-1;
        int ans=0,lmax=Integer.MIN_VALUE,rmax=Integer.MIN_VALUE;
        while(l<r){
            lmax=Math.max(lmax,arr[l]);
            rmax=Math.max(rmax,arr[r]);
            if(lmax<rmax){
                ans+=lmax-arr[l];
                l++;
            }else{
                ans+=rmax-arr[r];
                r--;
            }
        }
        return ans;
        
    }
}

