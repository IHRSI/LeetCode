//Bit mani my logic
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
//AS only 11 possibility are there we can use lower bound also after forming the array of all possible ans.
//Bit mani
class Solution {
public:
    int smallestNumber(unsigned n) {//TC=O(1), SC=O(1)
        return bit_ceil(n+1)-1;//O(1)
    }
};

//Mathn pattern logic
class Solution {
public:
    int smallestNumber(int n) {//TC=O(lohn), SC=O(1)
        int x = 1;
        while (x < n) {
            x = x * 2 + 1;
        }
        return x;
    }
};
