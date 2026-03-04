class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {//TC=O(n*m), SC=O(n+m)
        int ans=0;
        int m=mat.size();
        int n=mat[0].size();
        vector<int> rowpre(m,0);
        vector<int> colpre(n,0);
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(mat[i][j]){
                    ++rowpre[i];
                    ++colpre[j];
                }
            }
        }
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(mat[i][j]){
                    if(rowpre[i]==1 && colpre[j]==1) ++ans;
                }
            }
        }
        return ans;
    }
};
