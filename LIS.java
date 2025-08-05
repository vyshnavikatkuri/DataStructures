class LIS {
    public static int lowerbound(List<Integer>sub,int target){
        int l=0,r=sub.size()-1;
        int ans=-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(sub.get(mid)>=target){
                ans=mid;
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        return ans;
    }
    public int lengthOfLIS(int[] nums) {
        List<Integer>sub=new ArrayList<>();
        sub.add(nums[0]);
        int n=nums.length;
        for(int i=1;i<n;i++){
            if(nums[i]>sub.get(sub.size()-1)){
                sub.add(nums[i]);
            }else{
                int ind=lowerbound(sub,nums[i]);    
                sub.set(ind,nums[i]);
            }
        }
        return sub.size();
    }
}
//replicated the same space by changing values thats all  [1,2,3,5]
//lower bound [1,2,5,3] put 4 or insert 4  [1,2,0,3,1,4,5] //[1],[1,2],[0,2],[0,2,3],[1,2,3],[1,2,3,4],[1,2,3,4,5]
//arr[mid]>=target,ans=
//least index >=target
