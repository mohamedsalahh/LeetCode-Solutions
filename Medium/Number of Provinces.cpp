class Solution
{
public:
    vector<int> id, sz;
    int idx;

    int Find(int x)
    {
        int root = x;

        while (root != id[root])
            root = id[root];
        while (x != root)
        {
            int next = id[x];
            id[x] = root;
            x = next;
        }

        return root;
    }

    bool IsConnected(int a, int b)
    {
        return Find(a) == Find(b);
    }

    void Union(int x, int y)
    {
        int i = Find(x);
        int j = Find(y);

        if (i == j)
            return;

        if (sz[i] > sz[j])
        {
            id[j] = i;
            sz[i] += sz[j];
        }
        else
        {
            id[i] = j;
            sz[j] += sz[i];
        }
        idx--;
    }
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int n = isConnected.size();
        idx = n;
        id = sz = vector<int>(n, 1);

        for (int i = 0; i < n; ++i)
            id[i] = i;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (isConnected[i][j])
                    Union(i, j);
            }
        }
        return idx;
    }
};