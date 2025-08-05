#include<vector>
#include<limits>
using namespace std;
class Solution {
    public:
        bool ispossible(vector<int>& bloomDay,int day, int m, int k){
            int cnt=0;
            int noofbq=0;
            for(auto ele:bloomDay){
                if(ele<=day){
                    cnt++;
                }else{
                    noofbq+=(cnt/k);
                    cnt=0;
                }
            }
            noofbq+=(cnt/k);
            return (noofbq>=m);
        }
        int minDays(vector<int>& bloomDay, int m, int k) {
            long long val=m*1ll*k*1ll;
            int n=bloomDay.size();
            if(val>n) return -1;
            int maxele=INT_MIN,minele=INT_MAX;
            for(auto ele:bloomDay){
                maxele=max(maxele,ele);
                minele=min(minele,ele);
            }
            int left=minele,right=maxele;
            int ans=maxele;
            while(left<=right){
                int mid=left+(right-left)/2;
                if(ispossible(bloomDay,mid,m,k)){
                    ans=mid;
                    right=mid-1;
                }else{
                    left=mid+1;
                }
            }
            return ans;
        }
    };