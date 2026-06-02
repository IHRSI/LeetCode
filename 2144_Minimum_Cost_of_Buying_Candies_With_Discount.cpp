class Solution {
public:
    int minimumCost(vector<int>& cost) {//TC=O(nlogn), SC=O(logn)
        int ans=0,n=cost.size();
        sort(cost.begin(),cost.end());
        int candy=0;
        for(int i=n-1;i>=0;--i){
            if((++candy%3)!=0) ans+=cost[i];
        }
        return ans;
    }
};
