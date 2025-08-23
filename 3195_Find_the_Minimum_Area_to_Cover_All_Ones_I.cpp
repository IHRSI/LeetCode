class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {//TC=O(n*m) , SC=O(1)
        int row=grid.size();
        int col=grid[0].size();
        int a=row,b=0,c=col,d=0;
        for(int i=0;i<row;++i){
            for(int j=0;j<col;++j){
                if(grid[i][j]){
                    a=min(a,i);
                    b=max(b,i);//b=i;An optimization: For max_i, it is guaranteed that i is greater or equal to max_i. Thus, we can simply apply max_i = i.
                    c=min(c,j);
                    d=max(d,j);
                }
            }
        }
        return (b-a+1)*(d-c+1);
    }
};
//Surprisingly not, four traversals and breaking the loop for each when element is found is faster than one traversal.
class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {//TC=O(n*m) , SC=O(1)
        int row = grid.size();
        int col = grid[0].size();
        int top = row, bottom = -1, left = col, right = -1;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (grid[i][j] == 1) {
                    top = i;
                    break;
                }
            }
            if (top != row) break;
        }
        for (int i = row - 1; i >= 0; --i) {
            for (int j = 0; j < col; ++j) {
                if (grid[i][j] == 1) {
                    bottom = i;
                    break;
                }
            }
            if (bottom != -1) break;
        }
        for (int j = 0; j < col; ++j) {
            for (int i = 0; i < row; ++i) {
                if (grid[i][j] == 1) {
                    left = j;
                    break;
                }
            }
            if (left != col) break;
        }
        for (int j = col - 1; j >= 0; --j) {
            for (int i = 0; i < row; ++i) {
                if (grid[i][j] == 1) {
                    right = j;
                    break;
                }
            }
            if (right != -1) break;
        }
        return (bottom - top + 1) * (right - left + 1);
    }
};
