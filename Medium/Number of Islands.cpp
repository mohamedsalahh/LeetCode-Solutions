class Solution
{
public:
    vector<int> dr = {-1, 1, 0, 0};
    vector<int> dc = {0, 0, 1, -1};
    vector<vector<int>> vis;
    int n, m;

    bool isValid(vector<vector<char>> &grid, int x, int y, int n, int m)
    {
        if (x >= n || x < 0 || y >= m || y < 0)
            return false;
        if (grid[x][y] == '0')
            return false;
        return true;
    }

    void dfs(vector<vector<char>> &grid, int r, int c)
    {
        vis[r][c] = 1;
        for (int i = 0; i < 4; ++i)
        {
            if (isValid(grid, r + dr[i], c + dc[i], n, m) && !vis[r + dr[i]][c + dc[i]])
            {
                vis[r + dr[i]][c + dc[i]] = 1;
                dfs(grid, r + dr[i], c + dc[i]);
            }
        }
    }

    int numIslands(vector<vector<char>> &grid)
    {
        n = grid.size();
        m = grid[0].size();
        vis = vector<vector<int>>(n, vector<int>(m, 0));
        int ans = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (!vis[i][j] && grid[i][j] != '0')
                {
                    dfs(grid, i, j);
                    ans++;
                }
            }
        }
        return ans;
    }
};