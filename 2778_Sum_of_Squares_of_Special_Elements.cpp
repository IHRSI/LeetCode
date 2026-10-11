class Solution {
public:
    int sumOfSquares(vector<int>& nums) {//TC=O(n), SC=O(1)
        int ans=0,n=nums.size();
        for(int i=0;i<n;++i) if(n%(i+1)==0) ans+=nums[i]*nums[i];
        return ans;
    }
};

class Solution {
public:
    int sumOfSquares(vector<int>& nums) {//TC=O(sqrt(n)), SC=O(1)
        int ans=0,n=nums.size();
        for(int i=1;i*i<=n;++i){
            if(n%i==0){
                ans+=nums[i-1]*nums[i-1];
                if(i*i!=n) ans+=nums[n/i-1]*nums[n/i-1];
            }
        }
        return ans;
    }
};
