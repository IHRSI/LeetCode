//Goated simplified for TC=22ms
//Precomputed only once in TC=O(nloglogn)
//Rest all the test cases run in O(1)
//SC O(N+N)~O(N) - Defined globally - 32MB
const int N=5*1e6+1;
int prime_ct[N]={0};
bool is_pri[N];
bool precompute=false;
void sieve(){
    for(int i=0;i<N;++i) is_pri[i]=1;
    is_pri[0]=is_pri[1]=0;
    for(int i=2;i*i<N;++i){
        if(is_pri[i]){
            for(int j=i*i; j<N;j+=i){
                is_pri[j]=false;
            }
        }
    }
    for(int i=2;i<N;++i){
        prime_ct[i]=prime_ct[i-1]+is_pri[i];
    }
}

class Solution {
public:
    int countPrimes(int n) {
        if(!precompute){
            sieve();
            precompute=true;
        }
        if(n==0) return 0;
        return prime_ct[n-1];
    }
};

//SC=13mb improved TC=204ms degraded in perfomance.
class Solution {//TC=O(nloglogn) as its getting computed in every test case , SC=O(n) from O(2N)
public:
    int countPrimes(int n) {
        vector<bool> prime(n+1, true);
        prime[0] = prime[1] = false;
        int count = 0;
        for (int i = 2; i < n; i++) {
            if (prime[i]) {
                count++;
                for (int j = 2 * i; j < n; j += i) {
                    prime[j] = false;
                }
            }
        }
        return count;
    }
};

//While the basic sieve is efficient, it's doing some unnecessary work:
//It checks even numbers, even though all even numbers greater than 2 are not prime.
//It starts marking from 2∗i, which is often redundant, since smaller multiples were already marked.
//We can skip even numbers in both the outer and inner loops, and manually count 2 to save computation.
//Therefore a bit improved 
class Solution {//Runtime=159ms - Improved from previous method 
public:
    int countPrimes(int n) {
        if(n<=2) return 0;
        else{
        vector<bool>prime(n+1,true);
        prime[0]=0;
        prime[1]=0;
        prime[2]=1;
        int count=1;
        for(int i=3;i<n;i+=2){
            if(prime[i]){
                count++;
                for(int j=2*i;j<n;j=j+i){
                    prime[j]=0;
                }
            }
        }
        return count;
        }
    }
};
