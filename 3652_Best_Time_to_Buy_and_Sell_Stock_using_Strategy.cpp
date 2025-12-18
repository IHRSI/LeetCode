class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {//TC=O(n), SC=O(n)
        long long ans=0;
        int n=prices.size();
        vector<long long> profit(n);
        vector<long long> cost(n);
        cost[0]=prices[0];
        profit[0]=prices[0]*strategy[0];
        for(int i=1;i<n;++i){
            profit[i]=profit[i-1]+prices[i]*strategy[i];
            cost[i]=cost[i-1]+prices[i];
        }
        ans=profit[n-1];
        for(int i=0;i<n-k+1;++i){
            long long lpro=(i==0)?0:profit[i-1];
            long long rpro=profit[n-1]-profit[i+k-1];
            long long changecost=cost[i+k-1]-cost[i+k/2-1];
            ans=max(ans,lpro+rpro+changecost);
        }
        return ans;
    }
};
