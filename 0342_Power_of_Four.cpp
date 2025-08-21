class Solution {
public:
    bool isPowerOfFour(int n) {//TC=O(logn) , SC=O(1)
        while(n>0 && n%4==0){
            n/=4;
        }
        if(n==1) return 1;
        return 0;
    }
};

//Power of 4 always gives n%3==1.
class Solution {
public:
    bool isPowerOfFour(int n) //TC=O(1) , SC=O(1)
        return n>0 && (n & (n - 1)) == 0 && n % 3 == 1;
    }
};

/*
Odd position check
The 1 bit of a power of four lies in odd positions only.
We use the mask 0x55555555 (binary: 010101...) to ensure the bit is in the correct position.
(n & 0x55555555) != 0
*/
class Solution {//TC=O(1) , SC=O(1)
public:
    bool isPowerOfFour(int n) {
        return n>0 && (n & (n - 1)) == 0 && (n&0x55555555)!=0;
    }
};
