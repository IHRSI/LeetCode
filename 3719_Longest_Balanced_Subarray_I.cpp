//Just adding this line "if(n-i<=maxlen) break;" optimises the code very much and changes the runtime from 1600ms to 400ms and space from 400mb to 140mb
class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int maxlen=0,n=nums.size();
        unordered_set<int> even;
        unordered_set<int> odd;
        for(int i=0;i<n;++i){
            even.clear();
            odd.clear();
            //if(n-i<=maxlen) break;
            for(int j=i;j<n;++j){
                if(nums[j]&1) odd.insert(nums[j]);
                else even.insert(nums[j]);
                if(odd.size()==even.size()) maxlen=max(maxlen,j-i+1);
            }
        }
        return maxlen;
    }
};
//The abive soln is more efficient in terms of runtime and space used than below. Otherwise the logic is same in both.
class Solution {
public:
    int longestBalanced(vector<int>& nums) {//TC=O(n^2), SC=O(n)
        int maxlen=0,n=nums.size();
        for(int i=0;i<n;++i){
            unordered_set<int> even;
            unordered_set<int> odd;
            for(int j=i;j<n;++j){
                if(nums[j]&1) odd.insert(nums[j]);
                else even.insert(nums[j]);
                if(odd.size()==even.size()) maxlen=max(maxlen,j-i+1);
            }
        }
        return maxlen;
    }
};
