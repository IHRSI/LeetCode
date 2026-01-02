class Solution {//
public:
    int repeatedNTimes(vector<int>& nums) {//TC=O(n), SC=O(1)
        int n=nums.size();
        for(int i=0;i<n-2;++i){
            if(nums[i]==nums[i+1] || nums[i]==nums[i+2]) return nums[i];
        }
        return nums[n-1];//Edge case: {z,y,x,x} {x,y,z,x}
    }
};

//Using um
class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {//TC=O(n), SC=O(n)
        unordered_map<int,int> hash;
        for(int e: nums){
            ++hash[e];
            if(hash[e]==2) return e;
        }
        return 0;
    }
};
//Using set
class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {//TC=O(n), SC=O(n)
        unordered_set<int> hash;
        for(int e: nums){
            if(hash.find(e)!=hash.end()) return e;
            hash.insert(e);
        }
        return 0;
    }
};
