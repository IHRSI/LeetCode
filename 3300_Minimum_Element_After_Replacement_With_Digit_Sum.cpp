class Solution {
public:
    int minElement(vector<int>& nums) {//TC=O(nlogn), SC=O(1)
        int n=nums.size();
        for(int i=0;i<n;++i){
            int sum=0,e=nums[i];
            while(e>0){
                sum+=e%10;
                e/=10;
            }
            nums[i]=sum;
        }
        return *min_element(nums.begin(),nums.end());
    }
};
