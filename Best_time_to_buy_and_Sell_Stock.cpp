#include<bits/stdc++.h>
using namespace std;
class Solution {
    public int maxProfit(int[] prices) {
        int minprice=Integer.MAX_VALUE;
        int maxprofit=Integer.MIN_VALUE;
        for(int price:prices){
            minprice=Math.min(minprice,price);
            maxprofit=Math.max(maxprofit,price-minprice);
        }
        return maxprofit;
    }
};
//2
class Solution {
    public int maxProfit(int[] prices) {
        int profit=0;
        for(int i=1;i<prices.length;i++){
            if(prices[i]>prices[i-1]){
                profit+=prices[i]-prices[i-1];
            }
        }
        return profit;
    }
}