//Self Coded - Most Efficient
class Solution {
public:
    string smallestPalindrome(string s) {//TC=O(n), SC=O(1)
        int n=s.size();
        int arr[26]={0};
        for(int i=0;i<n/2;++i){
            ++arr[s[i]-'a'];
        }
        char mid;
        if(n&1) mid=s[n/2];
        int k=0;
        for(int i=0;i<26;++i){
            if(arr[i]){
                int ct=arr[i];
                while(ct>0){
                    s[k]='a'+i;
                    --ct;
                    ++k;
                }
            }
        }
        if(n&1){
            s[k]=mid;
            ++k;
        }
        for(int i=25;i>=0;--i){
            if(arr[i]){
                int ct=arr[i];
                while(ct>0){
                    s[k]='a'+i;
                    --ct;
                    ++k;
                }
            }
        }
        return s;
    }
};
