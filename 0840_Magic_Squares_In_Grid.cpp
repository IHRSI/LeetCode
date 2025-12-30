/*
Some properties on magic squares can simplify the code massively.
5 is in the center.
Each magic square is either a rotation or reflection of other! There are only 8!
Evens are always in the corners.
Also to add in magic sqaure, the sum of any row, col & diag is 15
*/
class Solution {
public:
    bool ismagic(vector<vector<int>> &mat, int r,int c){//This funtion is time constant so TC=O(1)
        int mask=0;
        for(int i=0;i<3;++i){
            for(int j=0;j<3;++j){
                int x=mat[r+i][c+j];
                if(x<1 || x>9) return false;
                else if(mask & (1<<x)) return false;//Duplication
                else mask=mask | (1<<x);
            }
        }
        int sum=15;
        if(mat[r][c]+mat[r+1][c+1]+mat[r+2][c+2]!=sum) return false;//diagonal
        if(mat[r][c+2]+mat[r+1][c+1]+mat[r+2][c]!=sum) return false;//opp diagonal

        for(int i=0;i<3;++i){
            if(mat[r+i][c]+mat[r+i][c+1]+mat[r+i][c+2]!=sum) return false;//row
            if(mat[r][c+i]+mat[r+1][c+i]+mat[r+2][c+i]!=sum) return false;//col
        }
        return true;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {//TC=O(n*m), SC=O(1)
        int n=grid.size();
        int m=grid[0].size();
        int ct=0;
        for(int i=0;i<n-2;++i){
            for(int j=0;j<m-2;++j){
                if(ismagic(grid,i,j)) ++ct;
            }
        }
        return ct;
    }
};
