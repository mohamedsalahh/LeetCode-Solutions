class Solution
{
public:
    bool isValid(int x, int y, vector<vector<int>> &grid, int n)
    {
        if (x < 0 || x >= n || y < 0 || y >= n)
            return false;
        if (grid[x][y] == 1)
            return false;
        return true;
    }
    vector<int> dr = {0, 0, 1, -1, -1, -1, 1, 1};
    vector<int> dc = {1, -1, 0, 0, -1, 1, -1, 1};
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        int n = grid.size();
        if (n == 1)
            return 1;
        vector<vector<bool>> vis(n, vector<bool>(n, 0));
        int ans = 1, level = 1, nextLevel = 0;
        queue<int> rq, cq;
        if (grid[0][0] == 1)
            return -1;
        rq.push(0);
        cq.push(0);
        vis[0][0] = 1;
        while (!rq.empty())
        {
            int x = rq.front(), y = cq.front();
            rq.pop();
            cq.pop();
            level--;
            for (int i = 0; i < 8; ++i)
            {
                if (isValid(x + dr[i], y + dc[i], grid, n) && !vis[x + dr[i]][y + dc[i]])
                {
                    if (x + dr[i] == n - 1 && y + dc[i] == n - 1)
                    {
                        return ans + 1;
                    }
                    rq.push(x + dr[i]);
                    cq.push(y + dc[i]);
                    vis[x + dr[i]][y + dc[i]] = 1;
                    nextLevel++;
                }
            }
            if (!level)
            {
                level = nextLevel;
                nextLevel = 0;
                ans++;
            }
        }
        return -1;
    }
};