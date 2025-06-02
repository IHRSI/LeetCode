class Solution {// TC=O(n) , SC=O(n) , Used prefix sum kind of logic ,greedyQ
public:
    int candy(vector<int>& rate) {
        int n=rate.size();
        vector<int> candy(n,1);
        int ans=n;
        for(int i=1;i<n;i++){
            if(rate[i]>rate[i-1]) candy[i]=candy[i-1]+1;
        }
        for(int i=n-2;i>=0;i--){
            if(rate[i]>rate[i+1]) candy[i]=max(candy[i],candy[i+1]+1);
        }
        ans=accumulate(candy.begin(),candy.end(),0);
        return ans;
    }
};
