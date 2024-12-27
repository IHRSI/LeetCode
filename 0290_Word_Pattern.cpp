class Solution {//TC- o(n+m) SC- O(m)  n-size of string, m-size of pattern
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char,string> m;
        vector<string> v;
        string temp="";
        for(char &c : s){//splitting the s to words
            if(c==' '){
                v.push_back(temp);
                temp="";
            }
            else temp+=c;
        }
        v.push_back(temp);
        if (pattern.size()!=v.size()) return 0;
        unordered_set<string> us;
        for(int i=0; i<pattern.size(); i++){
            if(m.find(pattern[i])==m.end()){
                if(us.find(v[i])==us.end()){
                    m[pattern[i]]=v[i];
                    us.insert(v[i]);
                }
                else{
                    return 0;
                }
            }
            else{
                if(m[pattern[i]]!=v[i]) return 0;
            }
        }
        return 1;
    }
};
