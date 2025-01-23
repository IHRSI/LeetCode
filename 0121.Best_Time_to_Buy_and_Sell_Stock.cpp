//Using 2 pointer not efficient
class Solution {
public:
    int maxProfit(vector<int>& prices) { // TC=O(n), SC=(1)
        if(prices.size()==1) return 0;
        int ans=0;
        int l=0,r=1;
        while(r<prices.size()){
            if(prices[r]>prices[l]){
                ans=max(ans,prices[r]-prices[l]);
                r++;
            }
            else{
                l++;
                r=l+1;
            }
        }
        return ans;
    }
};
