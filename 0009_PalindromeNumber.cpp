#include <bits/stdc++.h>
class Solution {
public:
    bool isPalindrome(int x) {//TC=O(logx) , SC=O(1)
        if (x<0) return 0;
        long r=0,t=x;//Overflow check
        while(t>0){
            r=r*10 + t%10;
            t=t/10;
        }
        return r==x;
    }
};
