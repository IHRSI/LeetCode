//My approach
class Solution {
public:
    string removeOuterParentheses(string s) {//TC=O(n), SC=O(n)
        string ans="";
        int n=s.size(), sub_sta_idx=0;
        int ct=0;
        for(int i=0;i<n;++i){
            if(s[i]=='(') ++ct;
            else{
                --ct;
                if(ct==0){
                    ans+=s.substr(sub_sta_idx+1,i-sub_sta_idx-1);
                    sub_sta_idx=i+1;
                }
            }
        }
        return ans;
    }
};

//Editorial way
class Solution {
public:
    string removeOuterParentheses(string s) {//TC=O(n), SC=O(n)
        int level = 0;
        string res;
        for (auto c : s) {
            if (c == ')') {
                level--;
            }
            if (level) {
                res.push_back(c);
            }
            if (c == '(') {
                level++;
            }
        }
        return res;
    }
};
