//Using the formula V*(V-1)=2E check is better tran checking the each component vertex degree which should equal V-1 as it saves space and comptation after traversal.
//We use formula in the dfs approach and the other way in the bsf approach. Both ways are there to check the connected component.
//DFS
class Solution {
public:
    void dfs(int node,vector<vector<int>> &adj, vector<bool> &vis, pair<int,int> &p){//TC=O(V+2E)~O(V+E), SC=O(V)
        if(vis[node]) return;
        vis[node]=1;
        ++p.first;
        p.second+=adj[node].size();
        for(int chi: adj[node]){
            dfs(chi,adj,vis,p);
        }
        return;
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {//TC=O(E+V+2E)~O(V+E), SC=O(V+2E+V+V)~O(V+E)
        vector<vector<int>> adj(n);
        for(int i=0;i<edges.size();++i){
            int a=edges[i][0],b=edges[i][1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        int ct=0;
        vector<bool> vis(n);
        for(int i=0;i<n;++i){
            if(!vis[i]){
                pair<int,int> p;
                dfs(i,adj,vis,p);
                if(p.first*(p.first-1)==p.second) ++ct;
            }
        }
        return ct;
    }
};

//BFS
class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {//TC=O(E+V+2E+V)~O(V+E), SC=O(V+2E+V+V+V)~O(V+E)
        vector<vector<int>> adj(n);
        for(int i=0;i<edges.size();++i){
            int a=edges[i][0],b=edges[i][1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        int ct=0;
        vector<bool> vis(n);
        for(int i=0;i<n;++i){
            if(!vis[i]){
                vector<int> comp;
                queue<int> q;
                q.push(i);
                vis[i]=1;
                while(!q.empty()){
                    int curr=q.front();
                    q.pop();
                    comp.push_back(curr);
                    for(int nei:adj[curr]){
                        if(!vis[nei]){
                            q.push(nei);
                            vis[nei]=1;
                        }
                    }
                }
                bool iscomp=1;
                int compsz=comp.size();
                for(int node:comp){
                    if(adj[node].size()!=compsz-1){
                        iscomp=0;
                        break;
                    }
                }
                if(iscomp) ++ct;
            }
        }
        return ct;
    }
};

//Adjacency List approach
class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {//TC=O(V+E+V*(VlogV+V)++V+2E)~O(V^2logV+E), SC-O(2V+2E+(V+2E)+V+logV+V)~O(V+E+logV)
        vector<vector<int>> adj(n);
        for(int i=0;i<n;++i){
            adj[i].push_back(i);
        }
        for(auto edge:edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        unordered_map<string,int> compfreq;
        for(int i=0;i<n;++i){
            vector<int> nebors=adj[i];
            sort(nebors.begin(),nebors.end());
            string key="";
            for(int num:nebors){
                key+=to_string(num)+",";
            }
            ++compfreq[key];
        }
        int compct=0;
        for(auto &p: compfreq){
            int size=count(p.first.begin(),p.first.end(),',');
            if(size==p.second) ++compct;
        }
        return compct;
    }
};
