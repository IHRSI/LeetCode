class Solution {
public:
    bool checkString(string s) {//TC=O(n), SC=O(1)
        for(int i=1;i<s.size();++i) if(s[i-1]=='b' && s[i]=='a') return 0;
        return 1;
    }
};

class Solution {
public:
    bool checkString(string s) {
        return s.find("ba")==string::npos;//TC=O(n), SC=O(1)
    }
};
