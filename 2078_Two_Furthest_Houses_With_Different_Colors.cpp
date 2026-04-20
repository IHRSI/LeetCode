//Brute Force
class Solution {
public:
    int maxDistance(vector<int>& colors) {//TC=O(n^2), SC=O(1)
        int n=colors.size();
        int ans=-1;
        for(int i=0;i<n;++i){
            for(int j=i+1;j<n;++j){
                if(colors[i]!=colors[j]) ans=max(ans,j-i);
            }
        }
        return ans;
    }
};
