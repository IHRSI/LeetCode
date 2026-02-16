//Lookup Soln
class Solution {//TC=O(256), SC=O(256) in precompute, TC=O(1), SC=O(1) per func call
public:
    int table[256];
    Solution() {
        for (int i = 0; i < 256; i++) {
            table[i] = reverseByte(i);
        }
    }
    int reverseByte(int b) {
        int ans = 0;
        for (int i = 0; i < 8; i++) {
            ans <<= 1;
            ans |= (b & 1);
            b >>= 1;
        }
        return ans;
    }
    int reverseBits(int n) {
        return (table[n & 0xff] << 24) |
               (table[(n >> 8) & 0xff] << 16) |
               (table[(n >> 16) & 0xff] << 8) |
               (table[(n >> 24) & 0xff]);
    }
};

class Solution {
public:
    int reverseBits(int n) {//TC=O(32)~O(1), SC=O(1)
        int ans=0;
        for(int i=0;i<32;++i){
            if(n&1){
                ans|=1<<(31-i);
            }
            n>>=1;
        }
        return ans;
    }
};
//Alternate Logic
class Solution {
public:
    int reverseBits(int n) {//TC=O(32)~O(1), SC=O(1)
        if(n==0) return 0;
        int ans=0;
        for(int i=0;i<32;++i){
            ans<<=1;
            ans|=n&1;
            n>>=1;
        }
        return ans;
    }
};


class Solution {
public:
    int reverseBits(int n) {//TC=O(64)~O(1), SC=O(32)~O(1)
        string s="00000000000000000000000000000000";
        int ans=0;
        for(int i=0;i<32;++i){
            if(n & (1<<i)) s[i]='1';
        }
        for(int i=0;i<32;++i){
            if(s[i]=='1'){
                ans |= 1<<(31-i);
            }
        }
        return ans;
    }
};
