class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> ans(n, vector<int>(n));

        int ndig = (n << 1) - 1; // total diagonals = 2*n - 1
        vector<vector<int>> v(ndig);

        // Step 1: Group elements by diagonals
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int diff = i - j; // diagonal index
                v[diff + n - 1].push_back(grid[i][j]);
            }
        }
        // Step 2: Sort diagonals
        int up = ndig / 2; // index of main diagonal
        for (int i = 0; i < up; ++i) {
            sort(v[i].begin(), v[i].end()); // ascending for upper diagonals
        }
        for (int i = up; i < ndig; ++i) {
            sort(v[i].begin(), v[i].end(), greater<int>()); // descending for lower diagonals
        }
        // Step 3: Put sorted values back into ans matrix
        vector<int> idx(ndig, 0); // track index for each diagonal
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int diff = i - j;
                int diag = diff + n - 1;
                ans[i][j] = v[diag][idx[diag]];
                idx[diag]++; // move to next sorted element in this diagonal
            }
        }
        return ans;
    }
};
