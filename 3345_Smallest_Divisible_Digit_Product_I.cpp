class Solution {
public:
    int smallestNumber(int n, int t) {//TC=O(10logn), SC=O(1)
        auto prod=[](int n){
            int p=1;
            while(n>0){
                p*=n%10;
                n/=10;
            }
            return p;
        };
        while(true){
            if(prod(n)%t==0) return n;
            ++n;
        }
        return 0;
    }
};
