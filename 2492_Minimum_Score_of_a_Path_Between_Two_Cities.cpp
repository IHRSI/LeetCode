//DFS
class Solution {
public:
    void dfs(int n1,unordered_map<int,vector<pair<int,int>>> &adj, vector<bool> &vis, int &mdis){//TC=O(E+V+2E)~O(V+E), SC=O(V) - worse case sparse graph
        vis[n1]=1;
        for(auto cnode: adj[n1]){
            int n2=cnode.first,dis=cnode.second;
            mdis = min(mdis, dis);
            if(vis[n2]) continue;
            dfs(n2, adj, vis, mdis);
        }
    }
    int minScore(int n, vector<vector<int>>& roads) {
        unordered_map<int,vector<pair<int,int>>> adj;
        for(auto &e: roads){//TC=O(E), SC=O(V+2E)~O(V+E)
            int n1=e[0],n2=e[1],dis=e[2];
            adj[n1].emplace_back(n2,dis);
            adj[n2].emplace_back(n1,dis);
        }
        vector<bool> vis(n+1);//SC=O(V)
        int mdis=INT_MAX;
        dfs(1,adj,vis,mdis);
        return mdis;
    }
};

//BSF
class Solution {
public:
    void bfs(int n1,unordered_map<int,vector<pair<int,int>>> &adj, vector<bool> &vis, int &mdis){//TC=O(E+V+2E)~O(V+E), SC=O(V/2)~O(V)- worst case balanced graph
        queue<int> q;
        q.push(n1);
        vis[n1]=1;
        while(!q.empty()){
            int n=q.front();
            q.pop();
            for(auto &[n2,d]: adj[n]){
                mdis=min(mdis,d);
                if(!vis[n2]){
                    vis[n2]=1;
                    q.push(n2);
                }
            }
        }
    }
    int minScore(int n, vector<vector<int>>& roads) {
        unordered_map<int,vector<pair<int,int>>> adj;
        for(auto &e: roads){//TC=O(E), SC=O(V+2E)~O(V+E)
            int n1=e[0],n2=e[1],dis=e[2];
            adj[n1].emplace_back(n2,dis);
            adj[n2].emplace_back(n1,dis);
        }
        vector<bool> vis(n+1);//SC=O(V)
        int mdis=INT_MAX;
        bfs(1,adj,vis,mdis);
        return mdis;
    }
};
