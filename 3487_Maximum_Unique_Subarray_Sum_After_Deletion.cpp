//Efficient
class Solution {//n<=200
public:
    int maxSum(vector<int>& nums) {//TC=O(n) or O(200) , SC=O(201) of bool type
        int ans=0;
        bool is_pos=false;
        vector<bool> v(201,0);
        for(int e:nums){//O(n)
            if(e>=0) is_pos=true;
            v[e+100]=true;
        }
        if(!is_pos) return *max_element(nums.begin(),nums.end());//O(n)
        else {
            for(int i=100;i<201;++i) if(v[i]) ans+=i-100;//O(200)
        }
        return ans;
    }
};

//Editorail soln, mine is better as i used vec<bool>
class Solution {
public:
    int maxSum(vector<int>& nums) {//TC=O(n) , SC=O(n)
        unordered_set<int> positiveNumsSet;
        for (int num : nums) {
            if (num > 0) {
                positiveNumsSet.emplace(num);
            }
        }
        if (positiveNumsSet.empty()) {
            return *max_element(nums.begin(), nums.end());
        }
        return accumulate(positiveNumsSet.begin(), positiveNumsSet.end(), 0);
    }
};
