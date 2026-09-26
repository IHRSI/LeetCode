class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {//TC=O(n+m), SC=O(n+m)
        unordered_map<string,string> um;
        int n=knowledge.size();
        for(int i=0;i<n;++i) um[knowledge[i][0]]=knowledge[i][1];
        string ans="";
        int m=s.size();
        for(int i=0;i<m;++i){
            if(s[i]=='('){
                ++i;
                string key="";
                while(s[i]!=')'){
                    key+=s[i];
                    ++i;
                }
                if(um.find(key)!=um.end()) ans+=um[key];
                else ans+='?';
                continue;
            }
            ans+=s[i];
        }
        return ans;
    }
};
