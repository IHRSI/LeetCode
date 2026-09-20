class Solution {
public:
    int reverseDegree(string s) {//TC=O(n), SC=O(1)
        int sum=0,n=s.size();
        for(int i=0;i<n;++i){
            sum+=(26-(s[i]-'a'))*(i+1);
        }
        return sum;
    }
};
