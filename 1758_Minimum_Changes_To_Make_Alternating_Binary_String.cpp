//Approach 2: Only Check One pattern '101010...' or '010101...'
class Solution {
public:
    int minOperations(string s) {//TC=O(n), SC=O(1)
        int start0=0;
        int n=s.size();
        for(int i=0;i<n;++i){
            if(i&1){
                if(s[i]=='0') ++start0;
            }
            else{
                if(s[i]=='1') ++start0;
            }
        }
        return min(start0,n-start0);
    }
};

//Approach 1: Start with Zero or Start with One
class Solution {
public:
    int minOperations(string s) {//TC=O(n), SC=O(1)
        int start0=0,start1=0;
        int n=s.size();
        for(int i=0;i<n;++i){
            if(i&1){
                if(s[i]=='0') ++start0;
                else ++start1;
            }
            else{
                if(s[i]=='1') ++start0;
                else ++start1;
            }
        }
        return min(start0,start1);
    }
};
