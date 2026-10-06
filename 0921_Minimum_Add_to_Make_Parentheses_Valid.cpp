class Solution {
public:
    int minAddToMakeValid(string s) {//TC=O(n), SC=O(1)
        int ans=0,st=0;
        for(char c: s){
            if(c=='(') ++st;
            else if(st==0) ++ans;
            else --st;
        }
        return ans+st;
    }
};
