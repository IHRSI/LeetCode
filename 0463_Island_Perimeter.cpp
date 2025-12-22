class Solution {//TC=O(n*m), SC=O(n*m)- due to recursion stack
public:
    int peri=0;
    void dfs(vector<vector<int>> &mat,int i,int j){
        int n=mat.size();
        int m=mat[0].size();
        if (i < 0 || i >= n || j < 0 || j >= m) {//boundary so edge this side will contri to perimeter
            peri++;
            return;
        }
        if(mat[i][j]==0){//Water so edge this side will contri to perimeter
            peri+=1;
            return;
        }
        if(mat[i][j]==-1) return;
        mat[i][j]=-1;//Visited mark
        dfs(mat,i-1,j);
        dfs(mat,i+1,j);
        dfs(mat,i,j-1);
        dfs(mat,i,j+1);
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;++i){
            bool done=false;
            for(int j=0;j<m;++j){
                if(grid[i][j]==1){
                    dfs(grid,i,j);
                    done=true;
                    break;
                }
            }
            if(done) break;
        }
        return peri;
    }
};

class Solution {//Here the whole loop runs till end but in the above soln we break out the loop after the dfs traversal so it has a bit better runtime
public:
    int islandPerimeter(vector<vector<int>>& grid) {//TC=O(n*m), SC=O(1)
        int n=grid.size();
        int m=grid[0].size();
        int peri=0;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(grid[i][j]==1){
                    peri+=4;
                    if(i>0 && grid[i-1][j]==1) peri-=2;
                    if(j>0 && grid[i][j-1]==1) peri-=2;
                }
            }
        }
        return peri;
    }
};
