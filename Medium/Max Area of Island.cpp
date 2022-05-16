class Solution
{
public:
    vector<int> dr = {-1, 1, 0, 0};
    vector<int> dc = {0, 0, 1, -1};
    int n, m;

    bool isValid(int x, int y, vector<vector<int>> &grid)
    {
        if (x >= n || x < 0 || y >= m || y < 0)
            return false;
        if (grid[x][y] == 0)
            return false;
        return true;
    }

    void dfs(int x, int y, vector<vector<int>> &grid, vector<vector<bool>> &vis, int &idx)
    {
        idx++;
        vis[x][y] = 1;

        for (int i = 0; i < 4; ++i)
        {
            if (isValid(x + dr[i], y + dc[i], grid) && !vis[x + dr[i]][y + dc[i]])
                dfs(x + dr[i], y + dc[i], grid, vis, idx);
        }
    }

    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        n = grid.size();
        m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, 0));
        int ans = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (!vis[i][j] && grid[i][j] != 0)
                {
                    int idx = 0;
                    dfs(i, j, grid, vis, idx);
                    ans = max(ans, idx);
                }
            }
        }
        return ans;
    }
};