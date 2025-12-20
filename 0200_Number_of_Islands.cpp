//Equivalent to finding no. of connected component in a graph
//Here no need of making a visited array as we convert 1 to 0 int the mat itself so its not visited next time
class Solution {
public:
    void dfs(int i,int j,vector<vector<char>> &mat){
        int n=mat.size();
        int m=mat[0].size();
        if(i<0 || j<0 || i>=n || j>=m) return;
        if(mat[i][j]=='0') return;//mark visited
        mat[i][j]='0';
        dfs(i-1,j,mat);
        dfs(i+1,j,mat);
        dfs(i,j-1,mat);
        dfs(i,j+1,mat);
    }
    int numIslands(vector<vector<char>>& grid) {//TC=O(n*m), SC=O(n*m)
        int ans=0;
        int r=grid.size();
        int c=grid[0].size();
        for(int i=0;i<r;++i){
            for(int j=0;j<c;++j){
                if(grid[i][j]=='0') continue;
                else dfs(i,j,grid);
                ++ans;
            }
        }
        return ans;
    }
};
