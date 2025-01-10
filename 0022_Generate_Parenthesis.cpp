//TC- O(2nCn), SC- O(Cn2n) , where Cn=2n!/(n+1)!n! to fine no. of possible combination
class Solution {
public:
    vector<string> res;
    void paren(string &s,int l,int r){
        if(l==0 && r==0){
            res.push_back(s);
            return;
        }
        if(l>0){
            s.push_back('(');
            paren(s,l-1,r);
            s.pop_back();
        }
        if(r>0 && r>l){
            s.push_back(')');
            paren(s,l,r-1);
            s.pop_back();
        }
        return ;
    }
    vector<string> generateParenthesis(int n) {
        string s="";
        paren(s,n,n);
        return res;
    }
};
