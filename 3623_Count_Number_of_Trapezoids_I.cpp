class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {//TC=O(n), SC=O(n)
        int ans=0;
        long long sum=0;
        unordered_map<int,int> um;
        int m=1e9+7;
        for(auto &p: points) um[p[1]]++;
        for(auto &[a,b]: um){
            long long pairs=b*1ll*(b-1)/2;
            ans=(ans+(sum*pairs)%m)%m;
            sum+=pairs;
        }
        return ans;
    }
};
