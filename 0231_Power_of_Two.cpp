//Bit Manipulation trick
class Solution {//TC=O(1) , SC=O(1)
public:
    bool isPowerOfTwo(int n) {
        return (n>0) && (n&(n-1))==0;
    }
};

class Solution {
public:
    bool isPowerOfTwo(int n) {//TC=O(31), SC=O(1)
        for(int i=0;i<31;++i){
            if(1<<i==n) return 1;
        }
        return 0;
    }
};

//Only 1 bit will be set if n is pow of two
class Solution {//TC=O(1) , SC=O(1)
public:
    bool isPowerOfTwo(int n) {
        return (n>0) && __builtin_popcount(n)==1;
    }
};

//Keep Dividing Until You Get Bored
//Recursive way
bool isPowerOfTwo(int n) {
    if (n <= 0) return false;
    while (n % 2 == 0) n /= 2;
    return n == 1;
}
