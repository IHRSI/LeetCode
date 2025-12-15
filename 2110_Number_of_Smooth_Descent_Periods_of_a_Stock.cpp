class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {//TC=O(n), SC=O(1)
        int n=prices.size();
        long long ans=1;
        int val=1;
        for(int i=1;i<n;++i){
            if(prices[i-1]-prices[i]==1) ++val;
            else val=1;
            ans+=val;
        }
        return ans;
    }
};
