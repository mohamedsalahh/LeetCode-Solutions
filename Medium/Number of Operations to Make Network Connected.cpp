class Solution
{
public:
    vector<int> id, sz;
    int noCom;

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
        noCom--;
    }
    int makeConnected(int n, vector<vector<int>> &connections)
    {
        noCom = n;

        if (connections.size() < n - 1)
            return -1;

        id = sz = vector<int>(n + 9, 1);

        for (int i = 0; i < n; ++i)
            id[i] = i;

        for (auto v : connections)
        {
            Union(v[0], v[1]);
        }

        return noCom - 1;
    }
};