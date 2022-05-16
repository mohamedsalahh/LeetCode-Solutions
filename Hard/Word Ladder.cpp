class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        queue<string> q;
        q.push(beginWord);
        int ans = 1;
        set<string> visited;
        while (!q.empty())
        {
            int n = q.size();
            for (int i = 0; i < n; i++)
            {
                string word = q.front();
                q.pop();

                if (word == endWord)
                    return ans;

                dict.erase(word);
                for (int j = 0; j < word.size(); j++)
                {
                    char temp = word[j];
                    for (int k = 0; k < 26; k++)
                    {
                        word[j] = k + 'a';
                        if (dict.find(word) != dict.end() && visited.find(word) == visited.end())
                        {
                            q.push(word);
                            visited.insert(word);
                        }
                    }
                    word[j] = temp;
                }
            }
            ans++;
        }
        return 0;
    }
};