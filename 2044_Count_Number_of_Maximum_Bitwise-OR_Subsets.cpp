//BitMasking
class Solution {//67ms
public:
    int countMaxOrSubsets(vector<int>& nums) {//TC=O(n*2^n) , SC=O(1)
        int ct=0;
        int n=nums.size();
        int mxor=0;
        for(auto e:nums) mxor|=e;
        int n2=1<<n;
        for(int msk=0;msk<n2;++msk){
            int temp=0;
            for(int j=0;j<n;++j){
                if((msk>>j)&1){
                    temp|=nums[j];
                }
            }
            if(mxor==temp) ++ct;
        }
        return ct;
    }
};

class Solution {//39ms
public:
    int countMaxOrSubsets(vector<int>& nums) {
        vector<int> nums2;
        for(auto e: nums) if(e) nums2.push_back(e);
        int ct=0;
        int n=nums2.size();
        int mxor=0;
        for(auto e:nums2) mxor|=e;
        int n2=1<<n;
        for(int msk=0;msk<n2;++msk){
            int temp=0;
            for(int j=0;j<n;++j){
                if((msk>>j)&1){
                    temp|=nums2[j];
                    if(mxor==temp){//Added this part to improve runtime
                        ++ct;
                        break;
                    }
                }
            }
          //Removed here part
        }
        return ct;
    }
};

//Backtracking enhanced(skipping some subsets)
class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int maxOR = 0;
        for (int num : nums) {
            maxOR |= num;
        }
        return backtrack(nums, maxOR, 0, 0);//TC=O(2^n) , SC=O(n)
    }
private:
    int backtrack(vector<int>& nums, int maxOR, int index, int currentOR) {
        if (index == nums.size()) {
            return currentOR == maxOR ? 1 : 0;
        }
        if (currentOR == maxOR) {//Sipping some subsets if we get max or value
            return 1 << (nums.size() - index);
        }
        int include = backtrack(nums, maxOR, index + 1, currentOR | nums[index]);
        int exclude = backtrack(nums, maxOR, index + 1, currentOR);
        return include + exclude;
    }
};

class Solution {//Just removed 0 from array to improve runtime - But didnt improve
public:
    int countMaxOrSubsets(vector<int>& nums) {
        vector<int> nums2;
        for(auto e: nums) if(e) nums2.push_back(e);
        int ct=0;
        int n=nums2.size();
        int mxor=0;
        for(auto e:nums2) mxor|=e;
        int n2=1<<n;
        for(int msk=0;msk<n2;++msk){
            int temp=0;
            for(int j=0;j<n;++j){
                if((msk>>j)&1){
                    temp|=nums2[j];
                }
            }
            if(mxor==temp) ++ct;
        }
        return ct;
    }
};
