class Solution {//2D difference array followed by prefix sum
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {//TC=O(n^2+ q.size()),SC=O(n^2)
        vector<vector<int>> diff(n+1,vector<int>(n+1));
        for(const auto &a: queries){
            int r1=a[0],c1=a[1],r2=a[2],c2=a[3];
            diff[r1][c1]+=1;
            diff[r1][c2+1]-=1;
            diff[r2+1][c1]-=1;
            diff[r2+1][c2+1]+=1;
        }
        vector<vector<int>> ans(n,vector<int>(n));
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                int x1=(i==0)?0: ans[i-1][j];
                int x2=(j==0)?0: ans[i][j-1];
                int x3=(i!=0 && j!=0)? ans[i-1][j-1]: 0;
                ans[i][j]=diff[i][j]+x1+x2-x3;
            }
        }
        return ans;
    }
};

class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& q) {//TC=O(q.size()*n^2) , SC=O(1)
        vector<vector<int>>mat(n,vector<int>(n,0));
        for(int i=0;i<q.size();i++){
            int r1=q[i][0];
            int c1=q[i][1];
            int r2=q[i][2];
            int c2=q[i][3];
            for(int j=r1;j<=r2;j++){
            for(int k=c1;k<=c2;k++){
                mat[j][k]+=1;
            }
            }
           
        }
         return mat;
    }
};
