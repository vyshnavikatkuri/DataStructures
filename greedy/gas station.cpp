#include<bits/stdc++.h>
// #include<vector
using namespace std;
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalgas=0,totalcost=0;
        for(auto i :gas){
            totalgas+=i;
        }
        for(auto i:cost){
            totalcost+=i;
        }
        if(totalgas<totalcost) return -1;
        int curgas=0,start=0;
        for(int i=0;i<gas.size();i++){
             curgas+=gas[i]-cost[i];
             if(curgas<0){
                start=i+1;
                curgas=0;
             }
        }
        return start;
    }
};