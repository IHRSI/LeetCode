class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {//TC=O(n), SC=O(1)
        string ans="";
        for(string &s: words){
            int tweight=0;
            for(char c: s){
                tweight+=weights[c-'a'];
            }
            ans+='z'-tweight%26;
        }
        return ans;
    }
};
