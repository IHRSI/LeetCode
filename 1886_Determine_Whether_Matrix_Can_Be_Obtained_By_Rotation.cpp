class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {//TC=O(4*n^2)~O(n^2), SC=O(1)
        if(mat==target) return true;
        int k=3,n=mat.size();
        while(k--){
            for(int i=0;i<n;++i){
                for(int j=i+1;j<n;++j){
                    swap(mat[i][j],mat[j][i]);
                }
            }
            for(int i=0;i<n;++i){
                reverse(mat[i].begin(),mat[i].end());
            }
            if(mat==target) return true;
        }
        return false;
    }
};
