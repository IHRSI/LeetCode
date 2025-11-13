class Solution {//See ed to understand
public:
    int minOperations(vector<int>& nums) {//TC=O(n^2*logM), SC=O(1)  where M is max value i nums
        int n=nums.size();
        int op=INT_MAX;
        int ct1=0;
        int g=0;
        for(int e: nums){
            if(e==1) ++ct1;
            g=__gcd(g,e);
        }
        if(ct1!=0) return n-ct1;
        else if(g>1) return -1;
        for(int i=0;i<n-1;++i){
            int gcd=nums[i];
            for(int j=i+1;j<n;++j){
                gcd=__gcd(gcd,nums[j]);
                if(gcd==1){
                    op=min(op,j-i);
                    break;
                }
            }
        }
        if(op!=INT_MAX) return op+(n-1);
        return -1;
    }
};
