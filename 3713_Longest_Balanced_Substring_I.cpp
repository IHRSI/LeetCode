class Solution {
public:
    int longestBalanced(string s) {//TC=O(n(26+n*26))~O(26*n^2)~O(n^2), SC=O(26)~O(1)
        int longest=0;
        int n=s.size();
        for(int i=0;i<n;++i){
            if(n-i<longest) break;
            int hsh[26]={0};
            for(int j=i;j<n;++j){
                bool check=true;
                int chr=s[j]-'a';
                ++hsh[chr];
                for(int e: hsh){
                    if(e>0 && e!=hsh[chr]){
                        check=false;
                        break;
                    }
                }
                if(check) longest=max(longest,j-i+1);
            }
        }
        return longest;
    }
};
