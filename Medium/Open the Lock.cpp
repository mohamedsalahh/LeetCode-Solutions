class Solution
{
public:
    int openLock(vector<string> &deadends, string target)
    {

        map<string, bool> mp, vis;
        queue<pair<string, int>> q;

        for (string x : deadends)
            mp[x] = 1;

        if (mp["0000"])
            return -1;
        q.push({"0000", 0});
        vis["0000"] = 1;

        int ans = INT_MAX;
        while (!q.empty())
        {
            string curr = q.front().first;
            int s = q.front().second;
            q.pop();
            if (curr == target)
                return s;
            for (int i = 0; i < 4; ++i)
            {
                string temp = curr;
                char c = temp[i];

                if (temp[i] == '9')
                    temp[i] = '0';
                else
                    temp[i]++;

                if (!mp[temp] && !vis[temp])
                {
                    vis[temp] = 1;
                    q.push({temp, s + 1});
                }

                temp = curr;

                if (temp[i] == '0')
                    temp[i] = '9';
                else
                    temp[i]--;

                if (!mp[temp] && !vis[temp])
                {
                    vis[temp] = 1;
                    q.push({temp, s + 1});
                }
            }
        }
        return -1;
    }
};