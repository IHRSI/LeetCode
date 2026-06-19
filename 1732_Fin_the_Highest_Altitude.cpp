class Solution {
public:
    int largestAltitude(vector<int>& gain) {// TC=O(n), SC=O(1)
        int ans=0,sum=0;
        for(int g: gain){
            sum+=g;
            ans=max(ans,sum);
        }
        return ans;
    }
};
