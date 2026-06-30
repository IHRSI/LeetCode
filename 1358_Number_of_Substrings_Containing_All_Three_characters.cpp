class Solution {
public:
    int numberOfSubstrings(string s) {//TC=O(2n)~O(n), SC=O(1)
        int ans=0,n=s.size();
        int abc[3]={0};
        int l=0,r=0;
        while(r<n){
            ++abc[s[r]-'a'];
            while(abc[0]>0 && abc[1]>0 && abc[2]>0){
                ans+=n-r;
                --abc[s[l]-'a'];
                ++l;
            }
            ++r;
        }
        return ans;
    }
};
