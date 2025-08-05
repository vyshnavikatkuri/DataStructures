#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int>arr={5,7,3,2,1,2,3,0,5};
    int maxcnt=0;
    int cnt=1;
    for(int i=1;i<arr.size();i++){
        if(arr[i]>arr[i-1]){
            cnt++;
            maxcnt=max(maxcnt,cnt);
        }else{
            cnt=1;
        }
    }
    cout<<maxcnt;
    return 0;
}