class Solution {
public:
    bool checkOnesSegment(string s) {//TC=O(1), SC=O(1)
        bool got0=0;
        for(char c: s){
            if(c=='0') got0=true;
            if(got0 && c=='1') return 0;
        }
        return 1;
    }
};

class Solution {
public:
    bool checkOnesSegment(string s) {//TC=O(1), SC=O(1)
        return s.find("01")==string::npos;
    }
};
