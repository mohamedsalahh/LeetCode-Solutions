class Solution
{
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges)
    {
        if (n == 1)
            return {0};

        vector<int> in(n, 0);
        vector<int> leafs, nextleafs;
        vector<vector<int>> adj(n);
        for (auto v : edges)
        {
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
            in[v[0]]++;
            in[v[1]]++;
        }

        for (int i = 0; i < n; ++i)
            if (in[i] == 1)
                leafs.push_back(i);

        int k = leafs.size();
        while (k < n)
        {
            for (int u : leafs)
            {
                for (auto v : adj[u])
                {
                    in[v]--;
                    if (in[v] == 1)
                        nextleafs.push_back(v);
                }
            }
            leafs = nextleafs;
            nextleafs.clear();
            k += leafs.size();
        }
        return leafs;
    }
};