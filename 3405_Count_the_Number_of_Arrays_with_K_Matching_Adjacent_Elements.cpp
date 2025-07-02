// For a fiven array of length we can have (n-1) max adjacent pairs.
//Formula derived - ans= (n-1)Ck * m * (m-1)^n-k-1
//50ms
class Solution {//TC=O(n+logM)=O(n) , SC=O(1)
public:
    const int M=1e9+7;
    int binexp(int a,int b,int Mod){//Iterative
        int res=1;
        while(b!=0){
            if(b&1) res=(res*1ll*a)%Mod;
            b>>=1;
            a=(a*1ll*a)%Mod;
        }
        return res;
    
    }
    int countGoodArrays(int n, int m, int k) {
        int ans=(m*1ll*binexp(m-1,n-1-k,M))%M;// ans= m * (m-1)^n-k-1
        int a=1,b=1,c=1;//a=n(n-1)! , b=(n-1-k)! , c=k!
        int fact=1;
        for(int i=1;i<n;++i){
            fact=(fact*1ll*i)%M;
            if(i==k) c=fact;
            if (i==n-1-k) b=fact;
        }
        a=fact;
        ans=(ans*1ll*a)%M;
        int den=(b*1ll*c)%M;
        ans=(ans*1ll*binexp(den,M-2,M))%M;
        return ans;
    }
};
/*
Why This Code is Faster
1. Precomputation of Factorials and Inverses (O(N))
fact[] and inv_fact[] are computed once globally using:
Forward pass to compute fact[i].
Reverse pass using modular inverses for inv_fact[i].
Future queries reuse this precomputed data in O(1).

Single-Time Initialization
The init() function is protected by a flag check:
if (fact[0]) return;
Ensures that factorials are precomputed only once even across multiple test cases.

 Why Faster in Practice:
Your code: computes factorials for each test case → more runtime per query.
This code: does all heavy work once → per query is just fast arithmetic and a single qpow.
The LeetCode judge may batch test cases → precomputation cost is essentially amortized over all.

| Feature               | Your Code (50ms) | This Code (0ms) |
| --------------------- | ---------------- | --------------- |
| Factorial Calculation | Per Query        | Precomputed     |
| Modular Inverse       | Per Query        | Precomputed     |
| Binary Exponentiation | 2 Calls          | 1 Call          |
| Memory Usage          | O(1)             | O(N)            |
| Query Processing Time | O(N + log M)     | O(log M)        |

*/
//Editorial Soln 0ms
const int MOD = 1e9 + 7;
const int MX = 1e5;

long long fact[MX];
long long inv_fact[MX];

class Solution {
    long long qpow(long long x, int n) {
        long long res = 1;
        while (n) {
            if (n & 1) {
                res = res * x % MOD;
            }
            x = x * x % MOD;
            n >>= 1;
        }
        return res;
    }

    long long comb(int n, int m) {
        return fact[n] * inv_fact[m] % MOD * inv_fact[n - m] % MOD;
    }
    void init() {
        if (fact[0]) {
            return;
        }
        fact[0] = 1;
        for (int i = 1; i < MX; i++) {
            fact[i] = fact[i - 1] * i % MOD;
        }
        //***Calc of inv fact
        inv_fact[MX - 1] = qpow(fact[MX - 1], MOD - 2);
        for (int i = MX - 1; i; i--) {
            inv_fact[i - 1] = inv_fact[i] * i % MOD;
        }
    }

public:
    int countGoodArrays(int n, int m, int k) {
        init();
        return comb(n - 1, k) * m % MOD * qpow(m - 1, n - k - 1) % MOD;
    }
};
