class Solution {
public:
    int minDeletionSize(vector<string>& strs) {//TC=O(n*m), SC=O(1)
        int n=strs.size();
        int m=strs[0].size();
        int ans=0;
        for(int j=0;j<m;++j){
            bool valid=true;
            for(int i=1;i<n;++i){
                if(strs[i][j]<strs[i-1][j]){
                    valid=false;
                    break;
                }
            }
            if(!valid) ++ans;
        }
        return ans;
    }
};

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {//TC=O(n*m*2), SC=O(n*m)
        int n=strs.size();
        int m=strs[0].size();
        vector<string> col(m);
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                col[j]+=strs[i][j];
            }
        }
        int ans=0;
        for(int j=0;j<m;++j){
            bool valid=true;
            for(int i=1;i<n;++i){
                if(col[j][i]<col[j][i-1]){
                    valid=false;
                    break;
                }
            }
            if(!valid) ++ans;
        }
        return ans;
    }
};
