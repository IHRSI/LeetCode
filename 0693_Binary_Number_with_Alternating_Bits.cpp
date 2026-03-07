//APPROACH 1: BITSET TC=O(logn), SC=O(logn)~no. of bits in n(no. of bits < 32)
class Solution {
public:
    bool hasAlternatingBits(int n) {
        bitset<32> num(n);
        int bits=log2(n);
        for(int i=0;i<bits;++i){
            if(num[i]==num[i+1]) return false;
        }
        return true;
    }
};

//APPROACH 2: Math TC=O(logn), SC=O(1)
class Solution {
public:
    bool hasAlternatingBits(int n) {
        int prevBit = n % 2;
        n /= 2;
        while (n > 0) {
            if (prevBit == n % 2) 
                return false;
            prevBit = n % 2;
            n /= 2;
        }      
        return true;
    }
};

//APPROACH 3: XOR TC=O(1), SC=O(1)
class Solution {
public:
    bool hasAlternatingBits(int n) {
        unsigned int x=n^(n>>1);
        return (x&(x+1))==0;
    }
};
