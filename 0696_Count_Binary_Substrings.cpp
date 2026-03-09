class Solution {
public:
    int countBinarySubstrings(string s) {//TC=O(n), SC=O(1)
        int n=s.size();
        int ans=0;
        int prevct=0,currct=1;
        for(int i=1;i<n;++i){
            if(s[i-1]!=s[i]){
                ans+=min(prevct,currct);
                prevct=currct;
                currct=1;
            }
            else ++currct;
        }
        return ans+min(prevct,currct);
    }
};
