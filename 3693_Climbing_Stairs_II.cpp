//Bottom up space optimised
class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {//TC=O(n), SC=O(1)
        int a=0,b=0,c=0;
        for(int i=0;i<n;++i){
            int nxt=min({a+9,b+4,c+1})+costs[i];
            a=b;
            b=c;
            c=nxt;
        }
        return c;
    }
};

//Top Down
class Solution {
public:
    int solve(int i, vector<int>& costs, vector<int>& dp) {//TC=O(n) - but i get tle, SC=O(n+n) : dp array+recursion stack
        if(i < 0) return 0;

        if(dp[i] != -1) return dp[i];

        return dp[i] = costs[i] + min({
            solve(i-1, costs, dp) + 1,
            solve(i-2, costs, dp) + 4,
            solve(i-3, costs, dp) + 9
        });
    }

    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp(n, -1);
        return solve(n-1, costs, dp);
    }
};
