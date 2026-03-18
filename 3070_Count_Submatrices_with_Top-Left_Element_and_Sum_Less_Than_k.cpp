class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {//TC=O(n*m), SC=O(1)
        int ct=0;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                int x=(i==0)?0:grid[i-1][j];
                int y=(j==0)?0:grid[i][j-1];
                int z=(i>0 && j>0)?grid[i-1][j-1]:0;
                grid[i][j]+=x+y-z;
                if(grid[i][j]<=k) ++ct;
                else break;
            }
        }
        return ct;
    }
};
