class Solution {
public:
    int robbery(vector<int>&arr){
        int prev2=0;
        int prev=arr[0];
        int curr;
        for(int i=1;i<arr.size();i++){
            int pick=arr[i];
            if (i>1) pick+=prev2;
            int nonpick=prev;
            curr=max(pick,nonpick);
            prev2=prev;
            prev=curr;
        }
        return prev;
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        vector<int>arr1(n-1);
        vector<int>arr2(n-1);
        for(int i=0;i<n-1;i++){
            arr1[i]=nums[i];
        }
        for(int i=1;i<n;i++){
            arr2[i-1]=nums[i];
        }
        int m=max(robbery(arr1),robbery(arr2));
        return m;
    }
};