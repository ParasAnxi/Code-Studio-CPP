#include <bits/stdc++.h> 
using namespace std;
int maximumProfit(vector<int> &prices){
    int max_profit = INT_MIN, n = prices.size();
    int min_price = prices[0];
    for(int i=1; i<n; ++i) {
        if(prices[i] < min_price)
            min_price = prices[i];
        else {
            int profit = prices[i] - min_price;
            max_profit = max(profit, max_profit);
        }
    }
    if(max_profit == INT_MIN) // no profit gained
        max_profit = 0;
    return max_profit;
}