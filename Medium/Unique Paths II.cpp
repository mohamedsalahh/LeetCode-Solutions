class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int n = obstacleGrid.size(), m = obstacleGrid[0].size();
        vector<vector<long long>> grid(n, vector<long long>(m, 0));
        int r = n - 1, c = m - 1;
        if (obstacleGrid[r][c])
            return 0;
        grid[r][c] = 1;
        for (int k = 0; k < min(n, m); ++k)
        {
            if (r != n - 1 && c != m - 1 && !obstacleGrid[r][c])
                grid[r][c] += grid[r][c + 1] + grid[r + 1][c];

            for (int i = r - 1; i >= 0; --i)
            {
                if (obstacleGrid[i][c])
                    continue;

                if (i != n - 1 && c != m - 1)
                    grid[i][c] += grid[i][c + 1] + grid[i + 1][c];
                else if (c != m - 1)
                    grid[i][c] += grid[i][c + 1];
                else if (i != n - 1)
                    grid[i][c] += grid[i + 1][c];
            }

            for (int i = c - 1; i >= 0; --i)
            {
                if (obstacleGrid[r][i])
                    continue;

                if (r != n - 1 && i != m - 1)
                    grid[r][i] += grid[r][i + 1] + grid[r + 1][i];
                else if (i != m - 1)
                    grid[r][i] += grid[r][i + 1];
                else if (r != n - 1)
                    grid[r][i] += grid[r + 1][i];
            }
            r--;
            c--;
        }
        return grid[0][0];
    }
};