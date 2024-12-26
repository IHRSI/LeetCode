// TC- O(n)  SC-O(2n)~O(n)
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> s;
        for(int &ele : nums){
            s[ele]+=1;
            if(s[ele]>1) return 1;
        }
        return 0;
    }
};
