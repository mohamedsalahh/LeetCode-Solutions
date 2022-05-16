class Solution
{
public:
    int maximalNetworkRank(int n, vector<vector<int>> &roads)
    {
        vector<vector<int>> adj(n);
        set<pair<int, int>> st;
        for (auto v : roads)
        {
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
            st.insert({v[0], v[1]});
            st.insert({v[1], v[0]});
        }
        int ans = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (i == j)
                    continue;

                int c = adj[i].size() + adj[j].size();
                if (st.find({i, j}) != st.end())
                    c--;
                ans = max(ans, c);
            }
        }
        return ans;
    }
};