//Efficient - bitmasking + and operation
class Solution {
public:
    int numberOfSpecialChars(string word) {//TC=O(n), SC=O(1)
        int upper=0,lower=0;
        for(char c: word){
            if(c>='A' && c<='Z') upper|=1<<(c-'A');
            else lower|=1<<(c-'a');
        }
        int ans=lower & upper;
        return __builtin_popcount(ans);
    }
};

//Using bitmasking
class Solution {
public:
    int numberOfSpecialChars(string word) {//TC=O(n+26), SC=O(1)
        int ans=0;
        int upper=0,lower=0;
        for(char c: word){
            if(c>='A' && c<='Z') upper|=1<<(c-'A');
            else lower|=1<<(c-'a');
        }
        for(int i=0;i<26;++i){
            if((upper&1) && (lower&1)) ++ans;
            upper>>=1;
            lower>>=1;
        }
        return ans;
    }
};

//Using Uset
class Solution {
public:
    int numberOfSpecialChars(string word) {//TC=O(n+26), SC=O(52)
        int ans=0;
        unordered_set<char> us(word.begin(),word.end());
        for(char c='a'; c<='z';++c){
            if(us.count(c) && us.count(c-'a'+'A')) ++ans;
        }
        return ans;
    }
};
