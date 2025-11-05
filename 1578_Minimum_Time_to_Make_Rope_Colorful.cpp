class Solution {//Greedy logical - My logic
public:
    int minCost(string colors, vector<int>& neededTime) {//TC=O(n), SC=O(1)
        int ans=0;
        int n=colors.length();
        for(int i=1;i<n;++i){
            int maxi=neededTime[i-1];
            ans+=maxi;
            while(colors[i-1]==colors[i]){
                ans+=neededTime[i];
                maxi=max(maxi,neededTime[i]);
                ++i;
            }
            ans-=maxi;
        }
        return ans;
    }
};

class Solution {//DP
public:
    int minCost(string colors, vector<int>& neededTime) {//TC=O(n), SC=(n)
        int n = colors.size();
        vector<int> dp(n, 0);
        for(int i = 1; i < n; i++)
        {
            if(colors[i] == colors[i - 1])
            {
                dp[i] = dp[i - 1] + min(neededTime[i], neededTime[i - 1]);
                neededTime[i] = max(neededTime[i], neededTime[i - 1]);
            }
            else
            {
                dp[i] = dp[i - 1];
            }
        }
        return dp[n - 1];
    }
};

class Solution {//DP Optimised
public:
    int minCost(string colors, vector<int>& neededTime) {//TC=O(n), SC=O(1)
        int totalCost = 0;
        int n = colors.size();
        
        for (int i = 1; i < n; i++) {
            if (colors[i] == colors[i - 1]) {
                totalCost += min(neededTime[i], neededTime[i - 1]);
                neededTime[i] = max(neededTime[i], neededTime[i - 1]);
            }
        }
        return totalCost;
    }
};
