class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        swap(n, m);
        vector<vector<int>> grid(n, vector<int>(m, 0));
        int r = n - 1, c = m - 1;
        grid[r][c] = 1;
        for (int k = 0; k < min(n, m); ++k)
        {
            if (r != n - 1 && c != m - 1)
                grid[r][c] += grid[r][c + 1] + grid[r + 1][c];

            for (int i = r - 1; i >= 0; --i)
            {
                if (i != n - 1 && c != m - 1)
                    grid[i][c] += grid[i][c + 1] + grid[i + 1][c];
                else if (c != m - 1)
                    grid[i][c] += grid[i][c + 1];
                else if (i != n - 1)
                    grid[i][c] += grid[i + 1][c];
            }

            for (int i = c - 1; i >= 0; --i)
            {
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