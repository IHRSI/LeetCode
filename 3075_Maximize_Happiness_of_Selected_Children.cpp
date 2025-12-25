class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {//TC=O(nlogn+n), SC=O(logn)
        sort(happiness.begin(),happiness.end(),greater<int>());
        int decri=0;
        long long sum=0;
        for(int e: happiness){ 
            if(e-decri>0) sum+=e-decri;
            else break;
            ++decri;
            if(--k==0) break;
        }
        return sum;
    }
};
