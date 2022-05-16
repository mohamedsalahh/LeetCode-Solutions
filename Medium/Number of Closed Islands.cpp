class Solution
{
public:
    vector<int> dr = {0, 0, 1, -1};
    vector<int> dc = {1, -1, 0, 0};

    int notValid = 0;
    bool brk = true;
    int n, m;
    bool isBorder(int i, int j)
    {
        return (i >= n || i < 0 || j >= m || j < 0);
    }
    bool isValid(int i, int j, vector<vector<int>> &grid)
    {
        if (i >= n || i < 0 || j >= m || j < 0)
            return 0;
        if (grid[i][j] == 1)
            return 0;
        else
            return 1;
    }
    void dfs(int i, int j, vector<vector<int>> &grid, vector<vector<bool>> &vis)
    {
        vis[i][j] = 1;

        for (int k = 0; k < 4; ++k)
        {
            if (isBorder(i + dr[k], j + dc[k]) && brk)
            {
                notValid++;
                brk = false;
            }
            if (isValid(i + dr[k], j + dc[k], grid) && !vis[i + dr[k]][j + dc[k]])
                dfs(i + dr[k], j + dc[k], grid, vis);
        }
    }
    int closedIsland(vector<vector<int>> &grid)
    {
        n = grid.size();
        m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, 0));

        int idx = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (!vis[i][j] && grid[i][j] == 0)
                {
                    idx++;
                    brk = 1;
                    dfs(i, j, grid, vis);
                }
            }
        }
        return (idx - notValid);
    }
};