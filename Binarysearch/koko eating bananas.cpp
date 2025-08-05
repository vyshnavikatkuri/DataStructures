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