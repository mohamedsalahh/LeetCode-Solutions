class Solution
{
public:
    bool isBibratite = true, brk = false;
    ;
    void dfs(int u, vector<vector<int>> &graph, vector<bool> &vis, vector<int> &col, int c = 0)
    {
        vis[u] = 1;
        col[u] = c;
        for (int v : graph[u])
        {
            if (brk)
                return;
            if (!vis[v])
                dfs(v, graph, vis, col, !c);
            else
            {
                if (col[v] == c)
                {
                    isBibratite = false;
                    brk = true;
                }
            }
        }
    }
    bool possibleBipartition(int n, vector<vector<int>> &dislikes)
    {
        vector<vector<int>> graph(n + 1);
        for (auto v : dislikes)
        {
            graph[v[0]].push_back(v[1]);
            graph[v[1]].push_back(v[0]);
        }
        vector<bool> vis(n + 1, 0);
        vector<int> col(n + 1, -1);
        for (int i = 1; i <= n; ++i)
        {
            if (!vis[i])
                dfs(i, graph, vis, col);
            if (!isBibratite)
                return false;
        }
        return true;
    }
};