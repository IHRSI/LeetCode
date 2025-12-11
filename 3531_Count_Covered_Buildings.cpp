class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {//TC=O(n), SC=O(4n)=O(n)
        int ans=0;
        vector<int> colmin(n+1,n+1),rowmin(n+1,n+1),colmax(n+1),rowmax(n+1);
        for(auto &e: buildings){
            int x=e[0],y=e[1];
            colmin[x]=min(colmin[x],y);
            colmax[x]=max(colmax[x],y);
            rowmin[y]=min(rowmin[y],x);
            rowmax[y]=max(rowmax[y],x);
        }
        for(auto &b: buildings){
            int x=b[0],y=b[1];
            if(x>rowmin[y] && x<rowmax[y] && y>colmin[x] && y<colmax[x]) ++ans;
        }
        return ans;
    }
};
