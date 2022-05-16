class Solution
{
public:
    int r = 6, c = 6;
    vector<int> dr = {-1, 1, 0, 0}, dc = {0, 0, 1, -1};
    bool isValid(int a, int b)
    {
        if (a < 0 || a >= r || b < 0 || b >= c)
            return false;
        return true;
    }

    bool DFS(int a, int b, string &word, vector<vector<char>> &board, int &idx, vector<vector<int>> &vis)
    {
        vis[a][b] = 1;
        idx++;
        for (int i = 0; i < 4; ++i)
        {
            if (isValid(a + dr[i], b + dc[i]))
            {
                if (board[a + dr[i]][b + dc[i]] == word[idx] && !vis[a + dr[i]][b + dc[i]])
                {
                    if (board[a + dr[i]][b + dc[i]] == word.back() && idx == word.size() - 1)
                        return true;
                    if (DFS(a + dr[i], b + dc[i], word, board, idx, vis))
                        return true;
                }
            }
        }
        vis[a][b] = 0;
        idx--;
        return false;
    }

    bool isOk(int a, int b, string word, vector<vector<char>> &board)
    {
        if (word.size() == 1)
            return true;
        int idx = 0;
        vector<vector<int>> vis(r, vector<int>(c, 0));
        return DFS(a, b, word, board, idx, vis);
    }
    
    bool exist(vector<vector<char>> &board, string word)
    {
        map<char, vector<pair<int, int>>> mp;
        r = board.size();
        c = board[0].size();
        for (int i = 0; i < r; ++i)
            for (int j = 0; j < c; ++j)
                mp[board[i][j]].push_back({i, j});

        for (auto p : mp[word[0]])
            if (isOk(p.first, p.second, word, board))
                return true;

        return false;
    }
};