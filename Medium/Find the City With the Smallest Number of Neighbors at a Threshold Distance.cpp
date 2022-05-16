class Solution
{
public:
    int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold)
    {
        int oo = 1e6;
        vector<vector<int>> dist(n, vector<int>(n, oo));
        for (auto x : edges)
        {
            dist[x[0]][x[1]] = x[2];
            dist[x[1]][x[0]] = x[2];
        }

        for (int i = 0; i < n; ++i)
            dist[i][i] = 0;

        for (int k = 0; k < n; k++)
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        int ans = INT_MAX, idx = 0;
        for (int i = 0; i < n; ++i)
        {
            int cnt = 0;
            for (int j = 0; j < n; ++j)
            {
                if (i == j)
                    continue;
                if (dist[i][j] <= distanceThreshold)
                    cnt++;
            }
            if (cnt <= ans)
            {
                ans = cnt;
                idx = i;
            }
        }
        return idx;
    }
};