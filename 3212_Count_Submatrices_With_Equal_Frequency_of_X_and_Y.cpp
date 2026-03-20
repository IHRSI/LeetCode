class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {//TC=O(n*m) with less if-else and indexing, SC=O(2n)
        int m = grid.size(), n = grid[0].size();
        int ans = 0;
        vector<int> px(n, 0), py(n, 0);
        for (int i = 0; i < m; i++) {
            int rowX = 0, rowY = 0;
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 'X') rowX++;
                else if (grid[i][j] == 'Y') rowY++;
                px[j] += rowX;
                py[j] += rowY;
                if (px[j] == py[j] && px[j] > 0) {
                    ans++;
                }
            }
        }
        return ans;
    }
};

class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {//TC=O(nm), SC=O(2nm)
        int ct=0;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> psumx(n,vector<int>(m));
        vector<vector<int>> psumy(n,vector<int>(m));
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(grid[i][j] == 'X') ++psumx[i][j];
                else if(grid[i][j] == 'Y') ++psumy[i][j];
                if (i > 0) {
                    psumx[i][j] += psumx[i - 1][j];
                    psumy[i][j] += psumy[i - 1][j];
                }
                if (j > 0) {
                    psumx[i][j] += psumx[i][j - 1];
                    psumy[i][j] += psumy[i][j - 1];
                }
                if (i > 0 && j > 0) {
                    psumx[i][j] -= psumx[i - 1][j - 1];
                    psumy[i][j] -= psumy[i - 1][j - 1];
                }
                if (psumx[i][j] == psumy[i][j] && psumx[i][j] > 0) {
                    ++ct;
                }
            }
        }
        return ct;
    }
};
