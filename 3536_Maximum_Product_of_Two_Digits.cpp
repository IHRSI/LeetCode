class Solution {
public:
    int maxProduct(int n) {//TC=O(logn), SC=O(1)
        int first=0,second=0;
        while(n>0){
            int dig=n%10;
            if(dig>first){
                second=first;
                first=dig;
            }
            else if(dig>second) second=dig;
            n/=10;
        }
        return first*second;
    }
};
