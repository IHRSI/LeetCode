class Solution {//TC=O(n+n+logn)~O(n), SC=O(n+height)~O(n)
    static constexpr int mod = 1e9 + 7;
    //Iterative exponentiation
    int qpow(int x, int y) {//TC=O(log(depth-1))~O(logn) - worst case,  SC=O(1)
        int res = 1;
        for (; y; y >>= 1) {
            if (y & 1) {
                res = 1ll * res * x % mod;
            }
            x = 1ll * x * x % mod;
        }
        return res;
    }
    /*BFS Approach - TC=O(n), SC=O(1) skewed, SC=O(n/2)~O(n) balanced
    queue<pair<int,int>> q; //{node, parent}
        q.push({1, -1});
        int depth = -1;
        while (!q.empty()) {
            int sz = q.size();
            ++depth;
            while (sz--) {
                auto [node, par] = q.front();
                q.pop();
                for (int nei : adj[node]) {
                    if (nei == par) continue;
                    q.push({nei, node});
                }
            }
        }
    */
    int dfs(vector<vector<int>>& g, int x, int f) {//TC=O(n), SC=O(height)~O(n) skewed - worst case, SC=O(logn) avg case
        int max_dep = 0;
        for (auto& y : g[x]) {
            if (y == f) {
                continue;
            }
            max_dep = max(max_dep, dfs(g, y, x) + 1);
        }
        return max_dep;
    }
public:
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<vector<int>> g(n + 1);
        for (auto& e : edges) {
            int u = e[0];
            int v = e[1];
            g[u].emplace_back(v);
            g[v].emplace_back(u);
        }
        int max_dep = dfs(g, 1, 0);
        return qpow(2, max_dep - 1);
    }
};
