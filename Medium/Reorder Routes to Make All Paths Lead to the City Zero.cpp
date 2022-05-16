class Solution
{
public:
    int ans = 0;
    void dfs(int u, vector<vector<pair<int, int>>> &adj, vector<bool> &vis)
    {
        vis[u] = 1;
        for (auto p : adj[u])
        {
            if (!vis[p.first])
            {
                if (p.second == 1)
                    ans++;
                dfs(p.first, adj, vis);
            }
        }
    }
    int minReorder(int n, vector<vector<int>> &connections)
    {
        vector<vector<pair<int, int>>> adj(n);
        vector<bool> vis(n, 0);
        for (auto v : connections)
        {
            adj[v[0]].push_back({v[1], 1}); // real edge
            adj[v[1]].push_back({v[0], 0}); // fake edge to make it undirected
        }
        dfs(0, adj, vis);
        return ans;
    }
};