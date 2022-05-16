class Solution
{
public:
    int minimumJumps(vector<int> &forbidden, int a, int b, int x)
    {
        vector<int> vis(1e4, 0);

        for (int i = 0; i < forbidden.size(); i++)
            vis[forbidden[i]] = 1;

        queue<pair<int, int>> q;
        q.push({0, 0});
        int minJumps = 0;

        while (!q.empty())
        {
            int s = q.size();
            for (int i = 0; i < s; i++)
            {
                pair<int, int> p = q.front();
                q.pop();
                int num = p.first;
                if (num == x)
                    return minJumps;

                if (vis[num])
                    continue;

                vis[num] = 1;

                if (p.second == 0 && num - b >= 0)
                    q.push({(num - b), 1});

                if (num <= 2000 + b)
                    q.push({(num + a), 0});
            }
            minJumps++;
        }
        return -1;
    }
};