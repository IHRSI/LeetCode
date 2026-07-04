//Using 0/1 BSF
class Solution {
public:
    static constexpr int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
    bool findSafeWalk(vector<vector<int>>& grid, int health) {// TC=O(R*C), SC=O(2R*C)~O(R*C)
        int r=grid.size();
        int c=grid[0].size();
        vector<vector<int>> dis(r,vector<int>(c,INT_MAX));
        deque<pair<int,int>> dq;
        dq.emplace_front(0,0);
        dis[0][0]=grid[0][0];
        while(!dq.empty()){
            auto [x,y]=dq.front();
            dq.pop_front();
            for(auto &[dx,dy]: dir){
                int nx=x+dx,ny=y+dy;
                if(nx<0 || nx>=r || ny<0 || ny>=c) continue;
                int ncost=dis[x][y]+grid[nx][ny];
                if(ncost>=health) continue;
                if(ncost<dis[nx][ny]){
                    dis[nx][ny]=ncost;
                    if(grid[nx][ny]==0) dq.emplace_front(nx,ny);
                    else dq.emplace_back(nx,ny);
                }
            }
        }
        return (dis[r-1][c-1]<health);
    }
};

//Using dijkstras - same implementation using pq insted of dequeue
class Solution {
public:
    typedef tuple<int,int,int> t;
    static constexpr int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
    bool findSafeWalk(vector<vector<int>>& grid, int health) {// TC=O(R*C*log(R*C)), SC=O(2R*C)~O(R*C)
        int r=grid.size();
        int c=grid[0].size();
        vector<vector<int>> dis(r,vector<int>(c,INT_MAX));
        priority_queue<t,vector<t>,greater<t>> pq;
        pq.emplace(grid[0][0],0,0);
        dis[0][0]=grid[0][0];
        while(!pq.empty()){
            auto [cost,x,y]=pq.top();
            pq.pop();
            for(auto &[dx,dy]:dir){
                int nx=x+dx,ny=y+dy;
                if(nx<0 || nx>=r || ny<0 || ny>=c) continue;
                int ncost=cost+grid[nx][ny];
                if(ncost>=health) continue;
                if(ncost<dis[nx][ny]){
                    dis[nx][ny]=ncost;
                    pq.emplace(ncost,nx,ny);
                }
            }
        }
        return (dis[r-1][c-1]<health);
    }
};
