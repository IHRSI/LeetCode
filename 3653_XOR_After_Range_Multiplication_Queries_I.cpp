//Brute Force
class Solution {
    static const int m=1e9+7;
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {//TC=(q*n+n)~O(q*n), SC=O(1)
        for(auto q: queries){
            int a=q[0],b=q[1],c=q[2],d=q[3];
            for(int i=a;i<=b;i+=c){
                nums[i]=(nums[i]*1ll*d)%m;
            }
        }
        int ans=0;
        for(auto num: nums) ans^=num;
        return ans;
    }
};
