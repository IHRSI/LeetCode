//Efficient
class Solution {//TC=O(b+log(b_mod))=O(b) , SC=O(1)
public:
    int superPow(int a, vector<int>& b) {
        int m=1140;//this is phi(1337) value as 1337(191*7) is not prime used etf formula
        int n=b.size();
        int b_mod=0;//b_mod=b%phi(1337)=b%1140
        for(int i=0;i<n;++i){//Forming number from dogits given in array (a+b)%M=((a%M)+(b%M))%M
            b_mod=(b_mod*10+b[i])%m;
        }
        if(b_mod==0) b_mod=1440;
        int M=1337;
        int ans=1;
        while(b_mod!=0){//BinExp - Iterative
            if(b_mod & 1) ans=(ans*1ll*a)%M;
            a=(a*1ll*a)%M;
            b_mod >>=1;
        }
        return ans;
    }
};
