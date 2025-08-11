Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.

Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.

Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

Return the minimum integer k such that she can eat all the bananas within h hours.

 

Example 1:

Input: piles = [3,6,7,11], h = 8
Output: 4
#include<vector>
#include<limits>

using namespace std;
class Solution {
    public:
        int minEatingSpeed(vector<int>& piles, int h) {
            int maxele=INT_MIN;
            for(int i=0;i<piles.size();i++){
                maxele=max(maxele,piles[i]);
            }
            int left=1,right=maxele;
            long long  totalhrs;int ans=maxele;
            while(left<=right){                              //same find smallest divisor for given threshold
                int mid=left+(right-left)/2;
                totalhrs=0;
                for(auto ele:piles){
                    totalhrs += ceil((double)ele/mid);   //tc:O(nlogM)
                }
                if(totalhrs<=h){
                    right=mid-1;
                    ans=mid;
                }
                else{
                    left=mid+1;
                }
            }
            return ans;
    
        }
    };
