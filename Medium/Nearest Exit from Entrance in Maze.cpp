class Solution
{
public:
    vector<int> dr = {0, 0, -1, 1};
    vector<int> dc = {1, -1, 0, 0};
    int n, m;

    bool isValid(int x, int y, vector<vector<char>> &maze)
    {
        if (x < 0 || x >= n || y < 0 || y >= m)
            return false;
        if (maze[x][y] == '+')
            return false;
        return true;
    }

    bool isBorder(int x, int y)
    {
        return (x == 0 || x == n - 1 || y == 0 || y == m - 1);
    }
    int nearestExit(vector<vector<char>> &maze, vector<int> &entrance)
    {
        n = maze.size();
        m = maze[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<int> rq, cq;

        vis[entrance[0]][entrance[1]] = 1;
        rq.push(entrance[0]);
        cq.push(entrance[1]);

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
                    if (isValid(x + dr[k], y + dc[k], maze) && !vis[x + dr[k]][y + dc[k]])
                    {
                        if (isBorder(x + dr[k], y + dc[k]))
                            return idx;
                        rq.push(x + dr[k]);
                        cq.push(y + dc[k]);
                        vis[x + dr[k]][y + dc[k]] = 1;
                    }
                }
            }
        }
        return -1;
    }
};