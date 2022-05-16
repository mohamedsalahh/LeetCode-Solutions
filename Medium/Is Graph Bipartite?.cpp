class Solution
{
public:
    bool isBibratite = true;
    void dfs(int u, vector<vector<int>> &graph, vector<bool> &vis, vector<int> &col, int c = 0)
    {
        vis[u] = 1;
        col[u] = c;
        for (int v : graph[u])
        {
            if (!vis[v])
                dfs(v, graph, vis, col, !c);
            else
            {
                if (col[v] == c)
                    isBibratite = false;
            }
        }
    }
    bool isBipartite(vector<vector<int>> &graph)
    {
        int n = graph.size();
        vector<bool> vis(n, 0);
        vector<int> col(n, -1);
        for (int i = 0; i < n; ++i)
        {
            if (!vis[i])
                dfs(i, graph, vis, col);
            if (!isBibratite)
                return false;
        }
        return true;
    }
};