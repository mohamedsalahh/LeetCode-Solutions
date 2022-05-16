class Solution
{
public:
    vector<int> dr = {0, 0, -1, 1};
    vector<int> dc = {1, -1, 0, 0};
    int n, m;
    
    bool isValid(int x, int y, vector<vector<int>> &mat)
    {
        if (x < 0 || x >= n || y < 0 || y >= m)
            return false;
        if (mat[x][y] != -1)
            return false;
        return true;
    }

    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {
        n = mat.size(), m = mat[0].size();
        queue<int> rq, cq;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (!mat[i][j])
                {
                    rq.push(i);
                    cq.push(j);
                }
                else
                    mat[i][j] = -1;
            }
        }
        while (!rq.empty())
        {
            int x = rq.front(), y = cq.front();
            rq.pop();
            cq.pop();
            for (int i = 0; i < 4; ++i)
            {
                if (isValid(x + dr[i], y + dc[i], mat))
                {
                    mat[x + dr[i]][y + dc[i]] = mat[x][y] + 1; // his parent + 1
                    rq.push(x + dr[i]);
                    cq.push(y + dc[i]);
                }
            }
        }
        return mat;
    }
};