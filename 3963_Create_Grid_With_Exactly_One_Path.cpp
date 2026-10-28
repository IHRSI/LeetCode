class Solution {
public:
    vector<string> createGrid(int m, int n) {//TC=O(n*m), SC=O(1)
        vector<string> ans(m);
        for(int j=0;j<n;++j) ans[0]+='.';
        for(int i=1;i<m;++i){
            for(int j=0;j<n-1;++j){
                ans[i]+='#';
            }
            ans[i]+='.';
        }
        return ans;
    }
};
