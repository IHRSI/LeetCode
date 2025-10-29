class Solution {
public:
    int smallestNumber(int n) {//TC=O(logn) , SC=O(1)
        if((n&(n+1))==0) return n;
        int ct=0;
        while(n>0){
            ++ct;
            n>>=1;
        }
        return (1<<ct)-1;
    }
};
