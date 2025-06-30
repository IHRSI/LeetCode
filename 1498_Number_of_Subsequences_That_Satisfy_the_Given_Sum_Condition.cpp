//Subsequence Q - intution was to sort first then proceed 
class Solution {//Efficient
public:
    int numSubseq(vector<int>& nums, int target) {//TC=O(nlogn) , SC=O(n) - pre computing pow of 2 upto n - saves recalc of pows of 2
        const int M=1e9+7;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int> pow2(n,1);//O(n)
        for(int i=1;i<n;++i){
            pow2[i]=((pow2[i-1]*1ll)<<1)%M;
        }
        int ans=0;
        int i=0,j=n-1;
        while(i<=j){//O(n)
            if(nums[i]+nums[j]<=target){
                ans=(ans+pow2[j-i])%M;//Using precomputed pow2 is much faster in practice because it avoids repeated log N operations.
                ++i;
            }
            else --j;
        }
        return ans;
    }
};

class Solution {//TC=O(nlogn) , SC=O(1)
public:
    const int M=1e9+7;
    int binexp(int a, int b){//Iterative BinExp, O(logn) base 10 - no.of bits in b
        int res=1;
        while(b>0){
            if(b&1) res=(res*1ll*a)%M;
            a=(a*1ll*a)%M;
            b>>=1;
        }
        return res;
    }
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int ans=0;
        int i=0,j=nums.size()-1;
        int mid;
        while(i<=j){//O(n*logn)
            if(nums[i]+nums[j]<=target){
                ans=(ans+0ll+binexp(2,j-i))%M;
                ++i;
            }
            else --j;
        }
        return ans;
    }
};

class Solution {//using UP is not efficient here the while runs nlogn times instead efficient one it was O(n).
public:
    int numSubseq(vector<int>& nums, int target) {
        const int M=1e9+7;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int> pow2(n,1);
        for(int i=1;i<n;++i){
            pow2[i]=(pow2[i-1]*2ll)%M;
        }
        int ans=0;
        int i=0,j=n-1;
        while(i<=j){
            if(nums[i]+nums[j]<=target){
                ans=(ans+pow2[j-i])%M;
                ++i;
            }
            else j=upper_bound(nums.begin()+i,nums.begin()+j,target-nums[i])-nums.begin()-1;//Works but not efficient here --j was better //O(logn)
        }
        return ans;
    }
};
