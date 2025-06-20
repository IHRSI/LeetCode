//Using 2 pointer this is also efficient
class Solution {
public:
    int maxProfit(vector<int>& prices) { // TC=O(n) 0ms, SC=(1)
        if(prices.size()==1) return 0;
        int ans=0;
        int l=0,r=1;
        while(r<prices.size()){
            if(prices[r]>prices[l]){
                ans=max(ans,prices[r]-prices[l]);
                r++;
            }
            else{
                l=r;
                ++r;
            }
        }
        return ans;
    }
};

// Efficient Greedy - one pass optimisation
class Solution { // TC=O(n) 0ms, SC=(1)
public:
    int maxProfit(vector<int>& prices) {
        int min_price = prices[0];
        int maxprof = 0;
        for(int i=1;i<prices.size();i++){
            if(prices[i]>min_price){
                maxprof = max(maxprof,prices[i]-min_price);
            }
            else min_price=prices[i];
        }
        return maxprof;
    }
};
