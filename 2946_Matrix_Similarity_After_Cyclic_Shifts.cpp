class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {//TC=O(n*m), SC=O(1)
        int n=mat.size();
        int m=mat[0].size();
        k%=m;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(i&1){
                    int new_j=(j-k+m)%m;
                    if(mat[i][j]!=mat[i][new_j]) return 0;
                }
                else{
                    int new_j=((j+k)%m);
                    if(mat[i][j]!=mat[i][new_j]) return 0;
                }
            }
        }
        return true;
    }
};
