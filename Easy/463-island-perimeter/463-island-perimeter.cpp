class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int ans = 0;
        int n = grid.size(), m = grid[0].size();
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < m; ++j)
            {
                if(grid[i][j] && (i-1 < 0 || grid[i-1][j] == 0))
                    ans++;
            }
        }
        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(grid[j][i] && (i-1 < 0 || grid[j][i-1] == 0))
                    ans++;
            }
        }
        return ans*2;
    }
};