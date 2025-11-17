class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {//TC=O(n),SC=O(1)
        int n=nums.size(),last1=-1;
        for(int i=0;i<n;++i){
            if(nums[i]){
                if(last1!=-1 && i-last1-1<k) return 0;//last1!=-1 this helps to skip the step when we encounter 1st 1
                else last1=i;
            }
        }
        return 1;
    }
};
