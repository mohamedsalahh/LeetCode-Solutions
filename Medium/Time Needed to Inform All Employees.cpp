class Solution
{
public:
    int ans = 0;
    void dfs(int u, vector<vector<int>> &adj, vector<int> &informTime, vector<int> &dis)
    {
        for (int v : adj[u])
        {
            dis[v] = dis[u] + informTime[u];
            ans = max(ans, dis[v]);
            dfs(v, adj, informTime, dis);
        }
    }
    int numOfMinutes(int n, int headID, vector<int> &manager, vector<int> &informTime)
    {
        vector<vector<int>> adj(n);
        vector<int> dis(n, 0);
        for (int i = 0; i < n; ++i)
        {
            if (manager[i] == -1)
                continue;
            adj[manager[i]].push_back(i);
        }
        dfs(headID, adj, informTime, dis);
        return ans;
    }
};