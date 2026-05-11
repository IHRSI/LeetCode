class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {//TC=O(n), SC=O(1)
        int n=nums.size();
        vector<int> ans;
        for(int i=n-1;i>=0;--i){
            int x=nums[i];
            while(x>0){
                ans.push_back(x%10);
                x/=10;
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {//TC=O(nlogM), SC=O(logM) , where M is max value in arr
        int n=nums.size();
        vector<int> ans;
        for(int i=0;i<n;++i){
            string s=to_string(nums[i]);
            for(int c: s){
                ans.push_back(c-'0');
            }
        }
        return ans;
    }
};
