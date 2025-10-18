class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {//TC=O(nlogn), SC=O(logn) - Goes in the recursive stack space used by the sorting algorithm is O(logn).
        sort(nums.begin(),nums.end());
        int ct=0,prev=INT_MIN;
        for(int ele: nums){
            int curr=min(max(prev+1,ele-k),ele+k);
            if(curr>prev){
                ++ct;
                prev=curr;
            }
        }
        return ct;
    }
};
