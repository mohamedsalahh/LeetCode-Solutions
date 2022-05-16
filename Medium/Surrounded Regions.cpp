class Solution
{
public:
    vector<int> id = vector<int>(40009);
    vector<int> sz = vector<int>(40009);
    int root(int x)
    {
        int root = x;
        while (id[root] != root)
        {
            root = id[root];
        }
        while (root != x)
        {
            int next = id[x];
            id[x] = root;
            x = next;
        }
        return root;
    }

    bool connected(int x, int y)
    {
        return root(x) == root(y);
    }

    void Union(int x, int y)
    {
        if (connected(x, y))
            return;
        int i = root(x);
        int j = root(y);
        if (sz[i] < sz[j])
        {
            id[i] = j;
            sz[j] += sz[i];
        }
        else
        {
            id[j] = i;
            sz[i] += sz[j];
        }
    }

    void solve(vector<vector<char>> &board)
    {
        int n = board.size(), m = board[0].size();
        for (int i = 0; i < 40009; ++i)
            id[i] = i;
        for (int i = 0; i < 40009; ++i)
            sz[i] = 1;

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (board[i][j] != 'X')
                {
                    if (i > 0 && board[i - 1][j] == 'O')
                        Union(i * m + j, (i - 1) * m + j);
                    if (i < n - 1 && board[i + 1][j] == 'O')
                        Union(i * m + j, (i + 1) * m + j);
                    if (j > 0 && board[i][j - 1] == 'O')
                        Union(i * m + j, i * m + (j - 1));
                    if (j < m - 1 && board[i][j + 1] == 'O')
                        Union(i * m + j, i * m + (j + 1));
                }
            }
        }
        vector<pair<int, int>> borders;

        for (int i = 0; i < n; ++i)
            borders.push_back({i, 0});
        for (int i = 0; i < m; ++i)
            borders.push_back({0, i});
        for (int i = 0; i < n; ++i)
            borders.push_back({i, m - 1});
        for (int i = 0; i < m; ++i)
            borders.push_back({n - 1, i});

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (board[i][j] != 'X')
                {
                    bool f = true;
                    for (pair<int, int> x : borders)
                    {
                        if (connected(i * m + j, x.first * m + x.second))
                        {
                            f = false;
                            break;
                        }
                    }
                    if (f)
                        board[i][j] = 'X';
                }
            }
        }
    }
};