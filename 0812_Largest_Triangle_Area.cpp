//Used Shoelace Formula: Area = (1/2) * |x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)|
class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {//TC=O(n^3), SC=O(1)
        int n=points.size();
        double ans=0;
        for(int i=0;i<n;++i){
            int x1,y1;
            x1=points[i][0];
            y1=points[i][1];
            for(int j=i+1;j<n;++j){
                int x2,y2;
                x2=points[j][0];
                y2=points[j][1];
                for(int k=j+1;k<n;++k){
                    int x3,y3;
                    x3=points[k][0];
                    y3=points[k][1];
                    ans=max(ans,abs(0.0+x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2))/2);
                }
            }
        }
        return ans;
    }
};
