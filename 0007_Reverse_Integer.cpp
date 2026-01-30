class Solution {
public:
    int reverse(int x) {//TC=O(logn), SC=O(1)
        long rev=0;
        while(x){
            int digit=x%10;
            if(rev*10+digit>INT_MAX || rev*10+digit<INT_MIN) return 0;
            rev=rev*10+digit;
            x/=10;
        }
        return (int)rev;
    }
};

class Solution {
public:
    int reverse(int x) {//TC=O(logn), SC=O(1)
        int rev = 0;
        while (x != 0) {
            int pop = x % 10;
            x /= 10;
            if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && pop > 7))
                return 0;
            if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && pop < -8))
                return 0;
            rev = rev * 10 + pop;
        }
        return rev;
    }
};
