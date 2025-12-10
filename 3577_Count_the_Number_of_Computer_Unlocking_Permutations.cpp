class Solution {
public:
    int countPermutations(vector<int>& complexity) {//TC=O(n), SC=O(1)
        int ans=1,m=1e9+7;
        int n=complexity.size();
        for(int i=1;i<n;++i){
            if(complexity[0]>=complexity[i]) return 0;
        }
        n=n-1;
        while(n){
            ans=(ans*1ll*n)%m;
            --n;
        }
        return ans;
    }
};
