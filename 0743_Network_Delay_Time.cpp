//Dijkstra Algorithm
class Solution {
public:
    typedef pair<int,int> p;
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {//TC=O(E+V+ElogE+E)~O(V+ElogE), SC=O(V+E+E+V)~O(V+E)
        vector<vector<p>> adj(n+1//SC=O(V+E)
        for(auto &eg: times){//TC=O(E)
            adj[eg[0]].emplace_back(eg[1],eg[2]);
        }
        priority_queue<p,vector<p>,greater<p>> pq;//SC=O(E)
        vector<int> dis(n+1,INT_MAX);//SC=O(V)
        pq.emplace(0,k);
        dis[k]=0;
        while(!pq.empty()){//TC=O(V+ElogV)
            auto [d,node]=pq.top();
            pq.pop();
            for(auto &[cn,cd]: adj[node]){
                if(d+cd<dis[cn]){
                    dis[cn]=d+cd;
                    pq.emplace(dis[cn],cn);
                }
            }
        }
        int ans=*max_element(dis.begin()+1,dis.end());
        return (ans!=INT_MAX)?ans:-1;
    }
};
