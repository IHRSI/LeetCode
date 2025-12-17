/*
Imagine you were a stock trader and you know the future prices for a given stock (This is the problem input).
Each day you would buy the stock if you knew you could sell it tomorrow for a profit (This is the greedy solution).
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {//TC=O(n), SC=O(1)
        int profit=0;
        for(int i=1;i<prices.size();++i){
            if(prices[i]>prices[i-1]) profit+=prices[i]-prices[i-1];
        }
        return profit;
    }
};
