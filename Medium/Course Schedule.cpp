class Solution
{
public:
    bool isCyclicUtil(int u, vector<int> &vis, vector<int> &recStack, vector<vector<int>> &adj)
    {
        vis[u] = 1;
        recStack[u] = 1;

        for (auto v : adj[u])
        {
            if (!vis[v] && isCyclicUtil(v, vis, recStack, adj))
                return true;
            else if (recStack[v])
                return true;
        }
        recStack[u] = 0;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> adj(numCourses);
        vector<int> vis(numCourses, 0);
        vector<int> recStack(numCourses, 0);

        for (auto v : prerequisites)
            adj[v[1]].push_back(v[0]);

        for (int i = 0; i < numCourses; i++)
            if(!vis[i])
                if (isCyclicUtil(i, vis, recStack, adj))
                    return false;

        return true;
    }
};