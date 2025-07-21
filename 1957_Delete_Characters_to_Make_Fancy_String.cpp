class Solution {
public:
    string makeFancyString(string s) {
        string ans;
        int n=s.size();
        int i=1;
        int ct=1;
        char c=s[0];
        while(i<n){
            if(s[i]==s[i-1]) ++ct;
            else ct=1;
            if(ct)
        }
        return ans;
    }
};
