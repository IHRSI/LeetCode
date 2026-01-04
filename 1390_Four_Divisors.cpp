class Solution {//Number Theory
public:
    int sumFourDivisors(vector<int>& nums) {//TC=O(n*sqrt(m)), SC=O(1)
        int ans=0;
        for(int ele: nums){
            int ct=0,sum=0;
            for(int i=1;i*i<=ele;++i){
                if(ele%i==0){
                    ++ct;
                    sum+=i;
                    if(ele/i!=i){
                        ++ct;
                        sum+=ele/i;
                    }
                }
                if(ct>4) break;
            }
            if(ct==4) ans+=sum;
        }
        return ans;
    }
};

//Best efficient
//Sieve 4- here the sieve() runs only one time
const int N=1e5+1;
int sum[N],divisor_ct[N];//SC=O(2N)
bool precomputed=false;
void sieve(){//TC=O(NlogN)
    precomputed=true;
    for(int i=1;i<N;++i){
        for(int j=i;j<N;j+=i){
            sum[j]+=i;
            ++divisor_ct[j];
        }
    }
}
class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {//TC=O(nums.size())
        if(!precomputed) sieve();
        int ans=0;
        for(int num: nums){
            if(divisor_ct[num]==4) ans+=sum[num];
        }
        return ans;
    }
};

//Sieve 4
//Your sieve solution has better asymptotic complexity, but worse runtime because the precomputation cost dominates for small inputs.
//Your sieve runs every time a Solution object is created
class Solution {
public:
    static const int N=1e5+1;
    int sum[N]={0},divisor_ct[N]={0};//SC=O(N)
    Solution(){//Constructor- TC=O(NlogN)
        for(int i=1;i<N;++i){
            for(int j=i;j<N;j+=i){
                sum[j]+=i;
                ++divisor_ct[j];
            }
        }
    }
    int sumFourDivisors(vector<int>& nums) {//TC=O(nums.size())
        int ans=0;
        for(int num: nums){
            if(divisor_ct[num]==4) ans+=sum[num];
        }
        return ans;
    }
};
