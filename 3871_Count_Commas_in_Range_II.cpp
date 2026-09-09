class Solution {
public:
    long long countCommas(long long n) {//TC=O(logn/3)~O(1), SC=O(1)
        long long p=1000,ans=0;
        while(p<=n){
            ans+=n-(p-1);
            p*=1000;
        }
        return ans;
    }
};

class Solution {
public:
    long long countCommas(long long n) {//TC=O(logn/3)~O(1), SC=O(1)
        return max(0ll,n-999)+max(0ll,n-999999)+max(0ll,n-999999999)+max(0ll,n-999999999999)+max(0ll,n-999999999999999);
    }
};
