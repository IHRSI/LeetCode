//Same as 2958 where k=2
class Solution {
public:
    int maximumLengthSubstring(string s) {//TC=O(n), SC=O(26)~O(1)   
        int n=s.size();
        int ans=0;
        int i=0,j=0;
        int arr[26]={0};
        while(j<n){
            int ch=s[j]-'a';
            ++arr[ch];
            while(arr[ch]>2){
                --arr[s[i]-'a'];
                ++i;
            }
            ans=max(ans,j-i+1);
            ++j;
        }
        return ans;
    }
};
