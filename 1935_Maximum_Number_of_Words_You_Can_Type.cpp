class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {//TC=O(m+n), SC=O(26)=O(1)
        vector<bool> broke(26,false);
        for(char c: brokenLetters){
            broke[c-'a']=true;
        }
        int ans=0;
        bool flag=true;
        for(char c: text){
            if(c==' '){
                if(flag) ++ans;
                flag=true;
            }
            else if(broke[c-'a']) flag=false;
        }
        if(flag) ++ans;
        return ans;
    }
};

class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {//TC=O(n+m), SC=O(n+26)
        vector<bool> broke(26,false);
        for(char c: brokenLetters){//O(m)
            broke[c-'a']=true;
        }
        stringstream ss(text);//Internally scans the entire string once O(n)
        string token;
        int ans=0;
        while(ss>> token){//O(n)
            int isvalid=true;
            for(char c: token){
                if(broke[c-'a']){
                    isvalid=false;
                    break;
                }
            }
            if(isvalid) ++ans;
        }
        return ans;
    }
};

class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {//TC=O(n*26), SC=O(n)
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
//Without using stringstream
class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {//TC=O(n*26), SC=O(n)
        int ans=0;
        int n=text.size();
        int i=0;
        while(i<n){
            string s;
            while(i<n && text[i]!=' '){
                s+=text[i];
                ++i;
            }
            bool present=false;
            for(char c: brokenLetters){
                if(s.find(c)!=string ::npos){
                    present=true;
                    break;
                }
            }
            if(!present) ++ans;
            ++i;
        }
        return ans;
    }
};
