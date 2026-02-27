class Solution {
public:
    int binaryGap(int n) {//TC=O(logn), SC=O(1)
        int ans=0;
        int last1=-1,i=0;
        while(n>0){
            if(n&1){
                if(last1!=-1) ans=max(ans,i-last1);
                last1=i;
            }
            n>>=1;
            ++i;
        }
        return ans;
    }
};
