/*
Time Complexity: O(L) in worst case eg - a#######...
, where L is the final length of res, because operations on larger strings happen only after progressively building them. For example, for "a#%#%#%", the work is:
1+2+2+4+4+8+8+⋯
which is a geometric series summing to O(L).
*/

class Solution {
public:
    string processStr(string s) {//TC=O(L), SC=O(1), L is the final length of the string
        string res="";
        for(char c: s){
            if(c>='a' && c<='z') res.push_back(c);
            else if(c=='*' && !res.empty()) res.pop_back();
            else if(c=='#') res+=res;
            else reverse(res.begin(),res.end());
        }
        return res;
    }
};
