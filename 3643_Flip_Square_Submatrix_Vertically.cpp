class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {//TC=O(k^2/2)~O(k^2), SC=O(1)
        int a=x,b=x+k-1;
        int m=grid[0].size();
        while(a<b){
            for(int j=y;j<=y+k-1;++j){
                swap(grid[a][j],grid[b][j]);
            }
            ++a;
            --b;
        }
        return grid;
    }
};
