class Solution {
public:
    bool isBalanced(string num) {
        int diff=0,sign=1;
        for(int i=0; i<num.length();i++){
            diff+=sign*(num[i]-'0');
            sign*=-1;
        }
        return diff==0;
    }
};
