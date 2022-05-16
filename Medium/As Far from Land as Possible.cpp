class Solution
{
public:
    vector<int> dr = {0, 0, -1, 1};
    vector<int> dc = {1, -1, 0, 0};

    int n, m;
    bool isValid(int i, int j)
    {
        if (i < 0 || i >= n || j < 0 || j >= m)
            return false;
        return true;
    }
    int maxDistance(vector<vector<int>> &grid)
    {
        n = grid.size();
        m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, 0));
        queue<int> rq, cq;
        int layer = 0, nextLayer = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (grid[i][j] == 1)
                {
                    rq.push(i);
                    cq.push(j);
                    vis[i][j] = 1;
                    layer++;
                }
            }
        }
        int i, j;
        int idx = 0;
        if (rq.size() == 0 || rq.size() == n * m)
            return -1;
        while (!rq.empty())
        {
            i = rq.front();
            j = cq.front();
            rq.pop();
            cq.pop();
            layer--;
            for (int k = 0; k < 4; ++k)
            {
                if (isValid(i + dr[k], j + dc[k]) && !vis[i + dr[k]][j + dc[k]])
                {
                    rq.push(i + dr[k]);
                    cq.push(j + dc[k]);
                    vis[i + dr[k]][j + dc[k]] = 1;
                    nextLayer++;
                }
            }
            if (!layer)
            {
                layer = nextLayer;
                nextLayer = 0;
                idx++;
            }
        }
        return idx - 1;
    }
};