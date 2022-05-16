class Solution
{
public:
    bool isCyclic(int u, vector<int> &vis, vector<int> &recStack, vector<vector<int>> &adj, vector<int> &toposort)
    {
        vis[u] = 1;
        recStack[u] = 1;

        for (auto v : adj[u])
        {
            if (!vis[v] && isCyclic(v, vis, recStack, adj, toposort))
                return true;
            else if (recStack[v])
                return true;
        }
        toposort.push_back(u);
        recStack[u] = 0;
        return false;
    }
    
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        int N = numCourses;
        vector<vector<int>> adj(N);
        vector<int> vis(N, 0);
        vector<int> recStack(N, 0);
        vector<int> toposort;

        for (auto v : prerequisites)
            adj[v[1]].push_back(v[0]);

        for (int i = 0; i < N; i++)
            if (!vis[i])
                if (isCyclic(i, vis, recStack, adj, toposort))
                    return {};
        reverse(toposort.begin(), toposort.end());
        return toposort;
    }
};