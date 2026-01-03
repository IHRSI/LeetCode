//Recursive DP+ Memo
class Solution {//TC=O(n*12*(12))=O(states*tc of each call/func)~O(n), SC=O(n*12+n)=O(states+ rec depth)=O(n)
public:
    const string states[12]={"RYR","RGR","YRY","YGY","GRG","GYG","RYG","RGY","YGR","YRG","GRY","GYR"};//3*2*2 ways
    vector<vector<int>> memo;//Total n*12 states
    const int m=1e9+7;
    int solve(int n,int i){
        if(n==0) return 1;
        if(memo[n][i]!=-1) return memo[n][i];
        int ways=0;
        for(int j=0;j<12;++j){
            if(i==j) continue;
            else{
                if(states[i][0]==states[j][0] || states[i][1]==states[j][1] || states[i][2]==states[j][2]) continue;
                ways=(ways+0ll+solve(n-1,j))%m;
            }
        }
        return memo[n][i]=ways;
    }
    int numOfWays(int n) {
        int ans=0;
        memo=vector<vector<int>>(n,vector<int>(12,-1));
        for(int i=0;i<12;++i){
            ans=(ans+0ll+solve(n-1,i))%m;
        }
        return ans;
    }
};

//Pattern Recognition
//For this understanding checkout the explanations on the Qs soln on leetcode
class Solution {
public:
    int numOfWays(int n) {//TC=O(n), SC=O(1)
        long long x=6,y=6;
        int m=1e9+7;
        for(int i=2;i<=n;++i){
            long long newx=(3*x+2*y)%m;
            long long newy=(2*x+2*y)%m;
            x=newx;
            y=newy;
        }
        return (x+y)%m;
    }
};
