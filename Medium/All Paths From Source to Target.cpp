class Solution
{
public:
    void dfs(int u, int d, vector<int> path, vector<vector<int>> &paths, vector<vector<int>> &adj)
    {
        path.push_back(u);
        if (u == d)
            paths.push_back(path);
        for (int v : adj[u])
            dfs(v, d, path, paths, adj);
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &adj)
    {
        int N = adj.size();
        vector<vector<int>> paths;
        vector<int> path;
        dfs(0, N - 1, path, paths, adj);
        return paths;
    }
};