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

class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        int a=row,b=0,c=col,d=0;
        for(int i=0;i<row;++i){
            for(int j=0;j<col;++j){
                if(grid[i][j]){
                    a=i;
                    break;
                }
            }
        }
        for(int i=row-1;i>=0;--i){
            for(int j=0;j<col;++j){
                if(grid[i][j]){
                    b=i;
                    break;
                }
            }
        }
        for(int i=0;i<col;++i){
            for(int j=0;j<row;++j){
                if(grid[j][i]){
                    c=j;
                    break;
                }
            }
        }
        for(int i=col-1;i>=0;--i){
            for(int j=0;j<row;++j){
                if(grid[j][i]){
                    d=j;
                    break;
                }
            }
        }
        return (b-a+1)*(d-c+1);
    }
};
