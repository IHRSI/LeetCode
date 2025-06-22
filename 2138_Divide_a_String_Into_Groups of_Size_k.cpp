/*It's a simulation of:
Sequential reading of characters in blocks
Dynamic padding (when needed)
Manual building of resulting substrings

Why is this a simulation problem?
Because you're not applying a mathematical formula or using a data structure directly — you're imitating how the task would be done manually, step by step:
Take k letters
If not enough, add fill
Store the group
Repeat
*/
class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {//TC=O(n+k), SC=O(n+k) , both are in worst case if n%k!=0 - The output array is included in the space complexity.
        vector<string> ans;
        for(int i=0;i<s.size();i+=k){
            string temp="";
            for(int j=i;j<i+k;++j){
                if(j<s.size()) temp.push_back(s[j]);
                else temp.push_back(fill);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};

//The last element in the array ans may need padding. We use the fill character fill to extend its length to k.
class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {//TC=O(n+k), SC=O(n+k) , both are in worst case if n%k!=0 - The output array is included in the space complexity.
        while (s.size() % k != 0) s.push_back(fill);//Used padding
        vector<string> ans;
        for (int i = 0; i < s.size(); i += k)
            ans.push_back(s.substr(i, k));
        return ans;
    }
};
