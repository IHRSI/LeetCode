//We reverse the problem logic to avoid repeated work(dfs on each cell) instead we:-
/*
Instead of simulating water flowing from every cell to oceans (which would be expensive), you do the reverse:
Start DFS from Pacific border cells
Start DFS from Atlantic border cells
Move only to equal or higher heights (reverse of water flow)
Mark which cells can reach each ocean
Take the intersection
*/

/*
DFS runtime 40ms bfs runtime 8ms , dfs space 30mb bsf space 22mmb
DFS ❌
Risk of stack overflow
Depends on recursion depth limit
Can crash for large grids

BFS ✅
No recursion
Stable for large input
Preferred in production
*/
//DFS
class Solution {
public:
    int n,m;
    vector<vector<int>> moves={{0,1},{0,-1},{1,0},{-1,0}};
    void dfs(int i,int j,vector<vector<bool>>& visited,vector<vector<int>> & mat){//Recursion depth can be O(n*m)
        visited[i][j]=true;
        for(auto pr: moves){
            int x=i+pr[0];
            int y=j+pr[1];
            if(x<0 || x>=n || y<0 || y>=m) continue;
            else if(visited[x][y]==true) continue;
            else if(mat[x][y]>=mat[i][j]) dfs(x,y,visited,mat);
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {//O(5*n*m+ 2*(n+m))~O(n*m) as overall the iteration happens in both the mat once only as if once marked visited we dont call dfs again, SC=O(n*m)*4
        n=heights.size();
        m=heights[0].size();
        vector<vector<bool>> pacific(n,vector<bool>(m,false));
        vector<vector<bool>> atlantic(n,vector<bool>(m,false));

        for(int i=0;i<m;++i){
            dfs(0,i,pacific,heights);
            dfs(n-1,i,atlantic,heights);
        }
        for(int j=0;j<n;++j){
            dfs(j,0,pacific,heights);
            dfs(j,m-1,atlantic,heights);
        }

        vector<vector<int>> ans;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(atlantic[i][j] && pacific[i][j]) ans.push_back({i,j});
            }
        }
        return ans;
    }
};
//BSF
class Solution {
public:
    int n, m;
    vector<vector<int>> moves = {{0,1},{0,-1},{1,0},{-1,0}};
    void bfs(queue<pair<int,int>>& q, vector<vector<bool>>& visited, vector<vector<int>>& heights) {
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            int i = cur.first;
            int j = cur.second;
            for (auto &pr : moves) {
                int x = i + pr[0];
                int y = j + pr[1];
                if (x < 0 || x >= n || y < 0 || y >= m) continue;
                if (visited[x][y]) continue;
                if (heights[x][y] >= heights[i][j]) {
                    visited[x][y] = true;
                    q.push({x, y});
                }
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {//TC=O(5*n*m+ 2*(n+m))~O(n*m), SC=O(n*m)*4
        n = heights.size();
        m = heights[0].size();
        vector<vector<bool>> pacific(n, vector<bool>(m, false));
        vector<vector<bool>> atlantic(n, vector<bool>(m, false));
        queue<pair<int,int>> qp, qa;
        for (int j = 0; j < m; j++) {
            pacific[0][j] = true;
            qp.push({0, j});
            atlantic[n - 1][j] = true;
            qa.push({n - 1, j});
        }
        for (int i = 0; i < n; i++) {
            pacific[i][0] = true;
            qp.push({i, 0});
            atlantic[i][m - 1] = true;
            qa.push({i, m - 1});
        }
        bfs(qp, pacific, heights);
        bfs(qa, atlantic, heights);
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
    }
};
