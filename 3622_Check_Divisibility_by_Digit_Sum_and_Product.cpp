class Solution {
public:
    bool checkDivisibility(int n) {//TC=O(logn), SC=O(1)
        int dpro=1, dsum=0;
        int num=n;
        while(n>0){
            int d=n%10;
            dsum+=d;
            dpro*=d;
            n/=10;
        }
        return num%(dsum+dpro)==0;
    }
};
