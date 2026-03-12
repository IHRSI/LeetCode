class Solution {
public:
    int bitwiseComplement(int n) {//TC=O(logn), SC=O(1)
        if(n==0) return 1;
        int bits=log2(n);
        for(int i=0;i<=bits;++i){
            n^=1<<i;
        }
        return n;
    }
};

class Solution {
public:
    int bitwiseComplement(int n) {//TC=O(1), SC=O(1)
        if(n==0) return 1;
        int bits=floor(log2(n))+1;
        int mask=(1<<bits)-1;
        return n^mask;
    }
};
