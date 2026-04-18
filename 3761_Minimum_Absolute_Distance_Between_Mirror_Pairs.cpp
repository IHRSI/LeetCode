class Solution {
public:
    int rev(int n){
        int num=0;
        while(n>0){
            num=num*10+n%10;
            n/=10;
        }
        return num;
    }
    int minMirrorPairDistance(vector<int>& nums) {//TC=O(nlog(num)), SC=O(n)
        unordered_map<int,int> um;
        int n=nums.size();
        int ans=n;
        for(int i=0;i<n;++i){
            if(um.find(nums[i])!=um.end()){
                ans=min(ans,i-um[nums[i]]);
            }
            um[rev(nums[i])]=i;
        }
        return ans<n?ans:-1;
    }
};
