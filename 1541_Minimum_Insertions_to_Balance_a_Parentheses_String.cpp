class Solution {
public:
    int minInsertions(string s) {//TC=O(n), SC=O(1)
        int n=s.size();
        int ans=0,st=0;
        for(int i=0;i<n;++i){
            if(s[i]=='(') ++st;
            else{
                if(st>0) --st;
                else ++ans;
                if(i+1<n && s[i+1]==')') ++i;
                else ++ans;
            }
        }
        return ans+(st*2);
    }
};
