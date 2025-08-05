#include<vector>
using namespace std;
class Solution {
    public:
        int findKRotation(vector<int> &nums)  {
            int n=nums.size();
            int left=0,right=n-1;
            while(left<=right){
                if(nums[left]<=nums[right]) return left;
                int mid=left+(right-left)/2;
                int next=(mid+1)%n;
                int prev=(mid+n-1)%n;
                if(nums[mid]<nums[prev]&&nums[mid]<nums[next]) return mid;
                //go to the unsorted half
                if(nums[mid]>=nums[left]){
                    left=mid+1;
                }else{
                    right=mid-1;
                }
            }
            
        }
    };