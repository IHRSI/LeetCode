class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {//TC=O(n*m), SC=O(1)
        int n=grid.size();
        int m=grid[0].size();
        long long totsum=0;
        for(auto &vec: grid) totsum+=accumulate(vec.begin(),vec.end(),0ll);
        if(totsum&1) return 0;
        totsum/=2;
        long long sum=0;
        for(auto &vec: grid){
            sum+=accumulate(vec.begin(),vec.end(),0ll);
            if(sum==totsum) return 1;
        }
        sum=0;
        for(int j=0;j<m;++j){
            for(int i=0;i<n;++i){
                sum+=grid[i][j];
            }
            if(sum==totsum) return 1;
        }
        return false;
    }
};
