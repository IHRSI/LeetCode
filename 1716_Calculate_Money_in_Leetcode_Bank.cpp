class Solution {
public:
    int totalMoney(int n) {//TC=O(n), SC=O(1)
        int ans=1,money=1;
        for(int i=2;i<=n;++i){
            if(i%7==1){
                money-=5;
                ans+=money;
            }
            else{
                ++money;
                ans+=money;
            }
        }
        return ans;
    }
};

//Used AP fromula logic
class Solution {
public:
    int totalMoney(int n) {//TC=O(1), SC=O(1)
        int k = n / 7;
        int F = 28;
        int L = 28 + (k - 1) * 7;
        int arithmeticSum = k * (F + L) / 2;
        
        int monday = 1 + k;
        int finalWeek = 0;
        for (int day = 0; day < n % 7; day++) {
            finalWeek += monday + day;
        }
        return arithmeticSum + finalWeek;
    }
};
