class Solution {
public:
    int minDeletionSize(vector<string>& strs) {//TC=O(n*m), SC=O(n)
        int del=0;
        int n=strs.size();
        int m=strs[0].size();
        vector<bool>  sorted(n-1);
        for(int j=0;j<m;++j){
            bool deleted=false;
            for(int i=0;i<n-1;++i){
                if(!sorted[i] && strs[i][j]>strs[i+1][j]){
                    del++;
                    deleted=true;
                    break;
                }
            }
            if(deleted) continue;
            for(int i=0;i<n-1;++i){
                if(!sorted[i] && strs[i][j]<strs[i+1][j]) sorted[i]=true;
            }
        }
        return del;
    }
};
