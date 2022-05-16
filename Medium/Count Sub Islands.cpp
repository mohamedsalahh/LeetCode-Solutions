class Solution
{
public:
    vector<int> dr = {0, 0, 1, -1};
    vector<int> dc = {1, -1, 0, 0};

    int notValid = 0;
    bool brk = true;
    int n, m;
    bool isValid(int i, int j, vector<vector<int>> &grid2)
    {
        if (i >= n || i < 0 || j >= m || j < 0)
            return 0;
        if (grid2[i][j] == 0)
            return 0;
        else
            return 1;
    }
    void dfs(int i, int j, vector<vector<int>> &grid1, vector<vector<int>> &grid2, vector<vector<bool>> &vis)
    {
        vis[i][j] = 1;
        if (grid1[i][j] == 0 && brk)
        {
            notValid++;
            brk = false;
        }
        for (int k = 0; k < 4; ++k)
        {
            if (isValid(i + dr[k], j + dc[k], grid2) && !vis[i + dr[k]][j + dc[k]])
                dfs(i + dr[k], j + dc[k], grid1, grid2, vis);
        }
    }
    int countSubIslands(vector<vector<int>> &grid1, vector<vector<int>> &grid2)
    {
        n = grid1.size();
        m = grid1[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, 0));

        int idx = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (!vis[i][j] && grid2[i][j] == 1)
                {
                    idx++;
                    brk = 1;
                    dfs(i, j, grid1, grid2, vis);
                }
            }
        }
        return (idx - notValid);
    }
};