class Solution {
public:
    bool uniformArray(vector<int>& nums1) {//TC=O(n), SC=O(1)
        int mn=nums1[0];
        bool hasodd=0;
        for(int e: nums1){
            if(e<mn) mn=e;
            if(e&1) hasodd=1;
        }
        if(mn&1) return 1;
        return !hasodd;
    }
};
