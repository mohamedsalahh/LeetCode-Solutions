class Solution
{
public:
    vector<char> chars = {'A', 'C', 'G', 'T'};
    int minMutation(string start, string end, vector<string> &bank)
    {
        if (start == end)
            return 0;
        if (bank.size() == 0)
            return -1;

        map<string, bool> mp, vis;
        for (string gen : bank)
            mp[gen] = 1;
        queue<pair<string, int>> q;
        q.push({start, 0});
        vis[start] = 1;

        while (!q.empty())
        {
            string curr = q.front().first;
            int s = q.front().second;
            q.pop();
            if (curr == end)
                return s;
            for (int i = 0; i < 8; ++i)
            {
                for (int j = 0; j < 4; ++j)
                {
                    string temp = curr;
                    temp[i] = chars[j];
                    if (mp[temp] && !vis[temp])
                    {
                        vis[temp] = 1;
                        q.push({temp, s + 1});
                    }
                }
            }
        }
        return -1;
    }
};