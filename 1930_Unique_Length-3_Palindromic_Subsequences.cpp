class Solution {//Used bitmask for counting unique lettes instead of us
public:
    int countPalindromicSubsequence(string s) {//TC=O(n+26n)=O(n), SC=O(26+26)=O(1)
        vector<int> srt(26,-1);
        vector<int> end(26,-1);
        int n=s.size();
        for(int i=0;i<n;++i){
            if(srt[s[i]-'a']==-1) srt[s[i]-'a']=i;
            end[s[i]-'a']=i;
        }
        int ans=0;
        for(int i=0;i<26;++i){
            if(srt[i]!=-1 && srt[i]!=end[i]){
                int l=srt[i];
                int r=end[i];
                int bitmask=0;
                for(int j=l+1;j<r;++j) bitmask|=1<<(s[j]-'a');
                ans+=__builtin_popcount(bitmask);
            }
        }
        return ans;
    }
};

class Solution {
public:
    int countPalindromicSubsequence(string s) {//TC=O(n+26n)=O(n), SC=O(26+26+26)=O(1)
        vector<int> srt(26,-1);
        vector<int> end(26,-1);
        int n=s.size();
        for(int i=0;i<n;++i){
            if(srt[s[i]-'a']==-1) srt[s[i]-'a']=i;
            end[s[i]-'a']=i;
        }
        int ans=0;
        for(int i=0;i<26;++i){
            if(srt[i]!=-1 && srt[i]!=end[i]){
                int l=srt[i];
                int r=end[i];
                unordered_set<int> us;
                for(int j=l+1;j<r;++j) us.insert(s[j]);
                ans+=us.size();
            }
        }
        return ans;
    }
};
