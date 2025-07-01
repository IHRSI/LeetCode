//Efficient - Used ETF and Euler concept
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

//Divide and Conquer method - without Recursion - else evrything same as below
//(a^b)^10 used this below(needed recursion) == used this here(recursion not needed) a(^10)^b
class Solution {//SC=O(1) as recursion is not there anymore
public:
    const int M=1337;
    int binexp(int c,int d){
        int pro=1;
        while(d!=0){
            if(d&1) pro=(pro*1ll*c)%M;
            c=(c*1ll*c)%M;
            d>>=1;
        }
        return pro;
    }
    int superPow(int a,vector<int> &b){
        int res = 1;
        a %= M;
        for (int i = b.size() - 1; i >= 0; --i) {
            res = (res * 1LL * binexp(a, b[i])) % M;
            a = binexp(a, 10);
        }
        return res;
    }
};

//Divide and Conquer method - Recursion
//a^b = (a^{last_digit}) * (a^{remaining_digits})^{10} mod M
class Solution {//TC=O(2*b*log(digit))=O(b*log(digit)) , SC=O(b) - due to recursion stack. //At each level, the recursive function:
//Stores local variables like last_dig, p1, and p2. Pushes a new frame on the call stack.
public:
    const int M=1337;
    int binexp(int c,int d){//O(log(digit)) , digit = 0 to 9
        int pro=1;
        while(d!=0){
            if(d&1) pro=(pro*1ll*c)%M;
            c=(c*1ll*c)%M;
            d>>=1;
        }
        return pro;
    }
    int superPow(int a,vector<int> &b){//This function gets called b.size() times
        if(b.size()==0) return 1;
        //Processing b from least significant digit to most significant digit.
        int last_dig=b[b.size()-1];
        int p1=binexp(a,last_dig);
        b.pop_back();
        int p2=binexp(superPow(a,b),10);
        return (p1*p2)%M;
    }
};
