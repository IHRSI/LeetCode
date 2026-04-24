class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {//TC=O(n), SC=O(1)
        int ctl=0,ctr=0,ct=0;
        for(char c: moves){
            if(c=='L') ++ctl;
            else if(c=='R') ++ctr;
            else ++ct;
        }
        return abs(ctl-ctr)+ct;
    }
};
