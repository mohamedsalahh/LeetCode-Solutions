class Solution
{
public:
    vector<int> dr = {1, -1, 0, 0};
    vector<int> dc = {0, 0, 1, -1};
    int n, m;

    bool isValid(int i, int j, vector<vector<int>> &heights, int height)
    {
        if (i < 0 || i >= n || j < 0 || j >= m)
            return false;
        if (height > heights[i][j])
            return false;
        return true;
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
    {
        n = heights.size();
        m = heights[0].size();
        vector<vector<int>> vis1(n, vector<int>(m, 0)), vis2(n, vector<int>(m, 0));
        ;
        queue<int> rq, cq;
        for (int i = 0; i < n; ++i)
        {
            rq.push(i);
            cq.push(0);
            vis1[i][0] = 1;
        }
        for (int i = 0; i < m; ++i)
        {
            rq.push(0);
            cq.push(i);
            vis1[0][i] = 1;
        }
        while (!rq.empty())
        {
            int i = rq.front(), j = cq.front();
            int height = heights[i][j];
            rq.pop();
            cq.pop();

            for (int k = 0; k < 4; ++k)
            {
                if (isValid(i + dr[k], j + dc[k], heights, height) && !vis1[i + dr[k]][j + dc[k]])
                {
                    rq.push(i + dr[k]);
                    cq.push(j + dc[k]);
                    vis1[i + dr[k]][j + dc[k]]++;
                }
            }
        }
        for (int i = 0; i < n; ++i)
        {
            rq.push(i);
            cq.push(m - 1);
            vis2[i][m - 1] = 1;
        }
        for (int i = 0; i < m; ++i)
        {
            rq.push(n - 1);
            cq.push(i);
            vis2[n - 1][i] = 1;
        }
        while (!rq.empty())
        {
            int i = rq.front(), j = cq.front();
            int height = heights[i][j];
            rq.pop();
            cq.pop();

            for (int k = 0; k < 4; ++k)
            {
                if (isValid(i + dr[k], j + dc[k], heights, height) && !vis2[i + dr[k]][j + dc[k]])
                {
                    rq.push(i + dr[k]);
                    cq.push(j + dc[k]);
                    vis2[i + dr[k]][j + dc[k]]++;
                }
            }
        }
        vector<vector<int>> ans;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (vis1[i][j] && vis2[i][j])
                    ans.push_back({i, j});
            }
        }
        return ans;
    }
};
