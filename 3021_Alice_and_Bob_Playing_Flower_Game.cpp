class Solution {
public:
    long long flowerGame(int n, int m) {//TC=O(1) , SC=O(1)
        int ao,ae,bo,be;
        if((n&1)==0){
            ao=n>>1;
            ae=ao;
        }
        else{
            ae=n>>1;
            ao=n-ae;
        }
        if((m&1)==0){
            bo=m>>1;
            be=bo;
        }
        else{
            be=m>>1;
            bo=m-be;
        }
        return ao*1ll*be +ae*1ll*bo;
    }
};

class Solution {
public:
    long long flowerGame(int n, int m) {//TC=O(1) , SC=O(1)
        long long ao = (n + 1) / 2;
        long long ae = n / 2;
        long long bo = (m + 1) / 2;
        long long be = m / 2;
        return ao * be + ae * bo;
    }
};
