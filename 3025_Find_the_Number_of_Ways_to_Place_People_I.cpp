//Brute Force(Editorial also gave O(n^3) soln)
class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {//TC=O(n^3) , SC=O(1)
        int ans=0,n=points.size();
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                if(j==i) continue;
                int x1=points[i][0];
                int y1=points[i][1];
                int x2=points[j][0];
                int y2=points[j][1];
                if(x1<=x2 && y1>=y2){
                    bool no_pt=true;
                    for(int k=0;k<n;++k){
                        if(k==i || k==j) continue;
                        int x3=points[k][0];
                        int y3=points[k][1];
                        if(x3>=x1 && x3<=x2 && y3<=y1 && y3>=y2){
                            no_pt=false;
                            break;
                        }
                    }
                    if(no_pt) ++ans;
                }
            }
        }
        return ans;
    }
};
