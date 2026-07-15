class Solution {
public:
    int gcdOfOddEvenSums(int n) {//TC=O(logn), SC=O(logn) goes in recursion
        int oddsum=n*n;
        int evensum=oddsum+n;
        return __gcd(oddsum,evensum);
    }
};
/*
first solution is eventually also O(1)
gcd(n * n, n * (n + 1)) -> gcd(n * (n + 1), n * n) -> gcd(n * n, n) -> gcd(n, 0) -> n
only 3 recursive call for any n > 1
*/
//WHich deduces that the gcd will always be n as gcd(n^2,n(n+1))=n*gcd(n,n+1)=n*1=n
class Solution {
public:
    int gcdOfOddEvenSums(int n) {//TC=O(1), SC=O(1)
        return n;
    }
};
