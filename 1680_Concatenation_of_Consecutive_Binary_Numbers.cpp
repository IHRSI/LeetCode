class Solution {
public:
    int concatenatedBinary(int n) {//TC=O(n), SC=O(1)
        long long ans=0;
        int m=1e9+7;
        for(int i=1;i<=n;++i){
            int bits=32- __builtin_clz(i);//int bits=__lg(i)+1;
            ans=((ans<<bits)+i)%m;
        }
        /* Alt Logic
        int bits=0;
        for(int i=1;i<=n;++i){
            if((i&(i-1))==0) ++bits;
        */
        return ans;
    }
};
