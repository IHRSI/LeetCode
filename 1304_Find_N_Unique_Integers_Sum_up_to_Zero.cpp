class Solution {
public:
    vector<int> sumZero(int n) {//TC=O(n/2) , SC=O(1)
        vector<int> ans;
        if((n&1)!=0) ans.push_back(0);
        for(int i=0;i<=n/2;++i){
            ans.push_back(i);
            ans.push_back(-i);
        }
        return ans;
    }
};
