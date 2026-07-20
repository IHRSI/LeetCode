//Both soln inspired frim LC 189

//Best approach
class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {//TC=O(n*m), SC=O(1)
        int n=grid.size();
        int m=grid[0].size();
        int sz=n*m;
        k%=sz;
        auto reverse=[&](int i,int j){
            while(i<j){
                swap(grid[i/m][i%m],grid[j/m][j%m]);
                ++i;
                --j;
            }
        };
        reverse(0,sz-1);
        reverse(0,k-1);
        reverse(k,sz-1);
        return grid;
    }
};

//Using additional space
class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {//TC=O(n*m), SC=O(n*m)
        int n=grid.size();
        int m=grid[0].size();
        int sz=n*m;
        k%=sz;
        vector<vector<int>> ans(n,vector<int>(m));
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                int oldidx=i*m+j;
                int newidx=(oldidx+k)%sz;
                ans[newidx/m][newidx%m]=grid[i][j];
            }
        }
        return ans;
    }
};
