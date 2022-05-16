class Solution
{
public:
    vector<int> dr = {0, 0, -1, 1};
    vector<int> dc = {1, -1, 0, 0};
    int n, m;

    bool isValid1(int x, int y, vector<vector<int>> &grid)
    {
        if (x < 0 || x >= n || y < 0 || y >= m)
            return false;
        return true;
    }

    bool isValid2(int x, int y, vector<vector<int>> &grid)
    {
        if (x < 0 || x >= n || y < 0 || y >= m)
            return false;
        if (grid[x][y] != 0)
            return false;
        return true;
    }

    int bfs(vector<vector<int>> &grid, vector<vector<int>> &island1)
    {
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<int> rq, cq;
        for (auto v : island1)
        {
            rq.push(v[0]);
            cq.push(v[1]);
        }
        int idx = 0;
        while (!rq.empty())
        {
            int sz = rq.size();
            idx++;
            for (int i = 0; i < sz; ++i)
            {
                int x = rq.front(), y = cq.front();
                rq.pop();
                cq.pop();
                for (int k = 0; k < 4; ++k)
                {
                    if (isValid1(x + dr[k], y + dc[k], grid) && grid[x + dr[k]][y + dc[k]] == 1)
                        return idx - 1;

                    if (isValid2(x + dr[k], y + dc[k], grid) && !vis[x + dr[k]][y + dc[k]])
                    {
                        rq.push(x + dr[k]);
                        cq.push(y + dc[k]);

                        vis[x + dr[k]][y + dc[k]] = 1;
                    }
                }
            }
        }
        return INT_MAX;
    }
    int shortestBridge(vector<vector<int>> &grid)
    {
        n = grid.size();
        m = grid[0].size();
        queue<int> rq, cq;
        vector<vector<int>> island1;

        for (int i = 0; i < n; ++i)
        {
            bool brk = 0;
            for (int j = 0; j < m; ++j)
            {
                if (grid[i][j] == 1)
                {
                    rq.push(i);
                    cq.push(j);
                    grid[i][j] = 2;
                    island1.push_back({i, j});
                    brk = 1;
                    break;
                }
            }
            if (brk)
                break;
        }

        int ans = INT_MAX;
        while (!rq.empty())
        {
            int x = rq.front(), y = cq.front();
            rq.pop();
            cq.pop();
            for (int k = 0; k < 4; ++k)
            {
                if (isValid1(x + dr[k], y + dc[k], grid) && grid[x + dr[k]][y + dc[k]] == 1)
                {
                    rq.push(x + dr[k]);
                    cq.push(y + dc[k]);
                    grid[x + dr[k]][y + dc[k]] = 2;
                    island1.push_back({x + dr[k], y + dc[k]});
                }
            }
        }

        ans = bfs(grid, island1);
        return ans;
    }
};