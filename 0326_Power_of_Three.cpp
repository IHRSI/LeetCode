//Basic Approach
class Solution {
public:
    bool isPowerOfThree(int n) {//TC=O(log3(n)),SC=(1)
        while(n>1 && n%3==0){
            n/=3;
        }
        if(n==1) return 1;
        return 0;
    }
};

//Divisibility by Maximum Power of Three of int range
class Solution {
public:
    bool isPowerOfThree(int n) {
        int x=log(INT_MAX)/log(3);
        int p=pow(3,x);
        return n>0 && p%n==0;
    }
};
