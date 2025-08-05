#include<vector>
#include<limits>
using namespace std;
class Solution {
    public:
        int findMin(vector<int>& nums) {
            int n=nums.size();
            int left=0,right=n-1;
            int ans=INT_MAX;
            while(left<=right){
                int mid=left+(right-left)/2;
                if(nums[left]<=nums[right]){
                      ans=min(ans,nums[left]);
                      break;
                } 
                if(nums[mid]>=nums[left]){
                    ans=min(nums[left],ans);
                    left=mid+1;
                }else{
                    ans=min(nums[mid],ans);
                    right=mid-1;
                }
            }
            return ans;
        }
    };