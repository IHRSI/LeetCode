class Solution {
public:
    bool canAliceWin(int n) {//TC=O(1), SC=O(1), as per Q n<50
        int i=10,k=0;
        while(n>=i){
            n-=i;
            --i;
            ++k;
        }
        return k%2==1;
    }
};
