class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {//TC=O(n^2), SC=O(n)
        if(count(s.begin(),s.end(),'1')<k) return "";
        int n=s.size();
        string ans="";
        int ct1=0;
        int i=0,j=0;
        while(j<n){
            if(s[j]=='1') ++ct1;
            while(ct1>k || s[i]=='0'){
                if(s[i]=='1') --ct1;
                ++i;
            }
            if(ct1==k){
                string t=s.substr(i,j-i+1);
                if(ans.empty() || t.size()<ans.size() || (t.size()==ans.size() && t<ans)) ans=t;
            }
            ++j;
        }
        return ans;
    }
};

//Brute Force neededthinking
class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {//TC=O(n^3), SC=O(n)
        int n=s.size();
        for(int len=k;len<=n;++len){
            string ans="";
            for(int i=0;i<=n-len;++i){
                string temp=s.substr(i,len);
                if(count(temp.begin(), temp.end(), '1')==k && (ans.empty() || temp<ans)) ans=temp;
            }
            if(!ans.empty()) return ans;
        }
        return "";
    }
};
