class Solution {
public:
    int numSub(string s) {//TC=O(n), SC=O(1)
        int ans=0,flow=0,m=1e9+7;
        int n=s.size();
        for(int i=0;i<n;++i){
            if(s[i]=='0'){
                flow=0;
                continue;
            }
            else{
                ++flow;
                ans=(ans+flow)%m;
            }
        }
        return ans;
    }
};
