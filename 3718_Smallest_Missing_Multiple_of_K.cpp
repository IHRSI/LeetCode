class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {//TC=O(2n)~O(n), SC=O(n)
        unordered_set<int> us(nums.begin(),nums.end());
        int ans=k;
        while(us.count(ans)) ans+=k;
        return ans;
    }
};

//Brute force but better time and space efficiency
class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {//TC=O(n*m), SC=O(1) , m is the mth multiple of k
        int ans=k;
        bool found=1;
        while(found){
            found=0;
            for(int &e: nums){
                if(ans==e){
                    found=1;
                    ans+=k;
                    break;
                }
            }
        }
        return ans;
    }
};
