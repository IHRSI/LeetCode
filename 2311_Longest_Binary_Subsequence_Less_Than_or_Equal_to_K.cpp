class Solution {
public:
    int longestSubsequence(string s, int k) {
        if(s=="") return 1;
        int ans=0;
        int val=0;
        long long pow2=1;
        int n=s.size();
        for(int i=n-1;i>=0;--i){
            if(s[i]=='0') ++ans;
            else{
                if(val+pow2<=k){
                    ++ans;
                    val+=pow2;
                }
            }
            if (pow2 <= k) pow2 <<= 1;
        }
        return ans;
    }
};
