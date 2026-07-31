// The smallest power of two greater than n is the no of distinct triplets.
class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {//TC=O(logn), SC=O(1)
        int n=nums.size();
        if(n<3) return n;
        int ans=1;
        while(ans<=n) ans<<=1;
        return ans;
    }
};
