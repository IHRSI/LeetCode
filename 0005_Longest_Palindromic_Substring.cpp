//Brute Force optimised - The time reduces drastically after optimisation
class Solution {
public:
    string longestPalindrome(string s) {//TC=O(n^3) - worst case TC but practically it is less time , SC=O(1)
        int n=s.size();
        auto ispalin=[&](int i,int j)->bool{
            while(i<j){
                if(s[i]==s[j]){
                    ++i;
                    --j;
                }
                else return false;
            }
            return true;
        };
        for(int len=n;len>0;--len){
            for(int i=0;i<=n-len;++i){
                if(ispalin(i,i+len-1)) return s.substr(i,len);
            }
        }
        return "";
    }
};

//Brute Force
class Solution {
public:
    string longestPalindrome(string s) {//TC=O(n^3), SC=O(1)
        int n=s.size();
        auto ispalin=[&](int i,int j)->bool{
            while(i<j){
                if(s[i]==s[j]){
                    ++i;
                    --j;
                }
                else return false;
            }
            return true;
        };
        int maxlen=0;
        int startidx=-1;
        for(int i=0;i<n;++i){
            for(int j=i;j<n;++j){
                if(ispalin(i,j)){
                    if(j-i+1>maxlen){
                        startidx=i;
                        maxlen=j-i+1;
                    }
                }
            }
        }
        return s.substr(startidx,maxlen);
    }
};
