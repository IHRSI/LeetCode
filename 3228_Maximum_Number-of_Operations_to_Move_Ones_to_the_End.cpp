class Solution {
public:
    int maxOperations(string s) {//TC=O(n), SC=O(1)
        int op=0,ct1=0;
        int n=s.size();
        for(int i=0;i<n;++i){
            if(s[i]=='1'){
                ++ct1;
                continue;
            }
            while(i+1<n && s[i+1]=='0') ++i;
            op+=ct1;
        }
        return op;
    }
};
