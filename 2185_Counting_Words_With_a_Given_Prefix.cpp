class Solution {// TC=O(m*n) in worst casegot 0ms, SC=O(1)
public:
    int prefixCount(vector<string>& words, string pref) {
        int count=0;
        for(int i=0; i<words.size();i++){
            int c1=0;
            for(int j=0;j<pref.size();j++){
                if (words[i][j]==pref[j]) c1+=1;
                else break;
            }
            if(c1==pref.size()) count+=1;
        }
        return count;
    }
};

//Using string functions
class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int count=0;
        for(int i=0; i<words.size();i++){
            if(words[i].starts_with(pref)) count+=1;
        }
        return count;
    }
};

// used substring func
class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int count=0;
        for(int i=0; i<words.size();i++){
            if(words[i].substr(0,pref.size())==pref) count+=1;
        }
        return count;
    }
};
