class Solution {
public:
    int mirrorDistance(int n) {//TC=O(logn), SC=O(1)
        int rev=0,num=n;
        while(num>0){
            rev=rev*10+num%10;
            num/=10;
        }
        return abs(n-rev);
    }
};
