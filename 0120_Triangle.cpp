class Solution {//Bottom Up DP
public:
    int minimumTotal(vector<vector<int>>& triangle) {//TC=O(n^2), SC=O(1)
        int ans=triangle[0][0];
        int n=triangle.size();
        int j=0;
        for(int i=n-2;i>=0;--i){
            for(int j=0;j<=i;++j){
                triangle[i][j]+=min(triangle[i+1][j],triangle[i+1][j+1]);
            }
        }
        return triangle[0][0];
    }
};
