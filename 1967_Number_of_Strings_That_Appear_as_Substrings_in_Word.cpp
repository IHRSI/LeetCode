//Brute Force
class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {//TC=O(n×∑mi), SC=O(1)
        int substrct=0;
        for(string &s:patterns){
            if(word.find(s)!=string::npos) ++substrct;
        }
        return substrct;
    }
};

//KMP
//Leave it waste of time
