class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {//TC=O(n*m), SC=O(n)
        int ans=0;
        string s;
        stringstream ss(text);
        while(ss>>s){
        //while(getline(ss,s,' ')){
            bool present=false;
            for(char c: brokenLetters){
                if(s.find(c)!=string ::npos){
                    present=true;
                    break;
                }
            }
            if(!present) ++ans;
        }
        return ans;
    }
};
