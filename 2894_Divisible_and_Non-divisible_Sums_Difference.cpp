class Solution { //TC=O(n) , SC=O(1)
public:
    int differenceOfSums(int n, int m) {
        int ans=0;
        int sum1=0;
        int sum2 =n*(n+1)/2;
        for(int i=1;i<=n;i++){
            if(i%m!=0) sum1+=i;
        }
        sum2-=sum1;
        return sum1-sum2;
    }
};

class Solution { // TC=O(1) using math intution, SC=O(1)
public:
    int differenceOfSums(int n, int m) {
        int k = n / m;
        return n * (n + 1) / 2 - k * (k + 1) * m;
    }
};
