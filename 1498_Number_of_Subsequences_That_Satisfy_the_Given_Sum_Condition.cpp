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
