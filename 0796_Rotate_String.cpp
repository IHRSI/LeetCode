class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size()!=goal.size()) return 0;
        int n=s.size();
        for(int i=0;i<n;++i){
            int k=0;
            for(int j=i;j<n+i;++j){
                if(s[j%n]==goal[k]) ++k;
            }
            if(k==n) return 1;
        }
        return 0;
    }
};
