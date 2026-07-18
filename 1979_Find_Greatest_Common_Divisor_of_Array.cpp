class Solution {
public:
    int findGCD(vector<int>& nums) {//TC=O(n+log(ls)), SC=O(1)
        int gr=*max_element(nums.begin(),nums.end());
        int ls=*min_element(nums.begin(),nums.end());
        return gcd(gr,ls);
    }
};
