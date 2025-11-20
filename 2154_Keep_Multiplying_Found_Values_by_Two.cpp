class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {//TC=O(nlogn), SC=O(logn)
        sort(nums.begin(),nums.end());
        for(int e: nums){
            if(original==e) original*=2;
            else if(original<e) break;
        }
        return original;
    }
};


class Solution {//Stil, gives bad runtime than above cause using us
public:
    int findFinalValue(vector<int>& nums, int original) {//TC=O(n), SC=O(n)
        unordered_set<int> us(nums.begin(),nums.end());
        while(us.count(original)){
            original*=2;
        }
        return original;
    }
};
