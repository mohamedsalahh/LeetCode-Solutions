class Solution
{
public:
    vector<string> fullJustify(vector<string> &words, int maxWidth)
    {
        queue<string> q;
        int lineWidth = 0;
        reverse(words.begin(), words.end());
        string line = "";
        vector<string> result;
        while (words.size())
        {
            if (lineWidth + words.back().size() + q.size() <= maxWidth)
            {
                q.push(words.back());
                lineWidth += words.back().size();
                words.pop_back();
            }
            else
            {
                if (q.size() == 1)
                {
                    line += q.back();
                    q.pop();
                    int cnt = maxWidth - lineWidth;
                    for (int i = 0; i < cnt; ++i)
                        line += " ";
                    result.push_back(line);
                    line = "";
                }
                else
                {
                    int spacesCnt = maxWidth - lineWidth;
                    int mod = spacesCnt % (q.size() - 1);
                    int cnt = spacesCnt / (q.size() - 1);
                    while (q.size())
                    {
                        line += q.front();
                        q.pop();
                        if (q.size())
                        {
                            if (mod)
                            {
                                for (int i = 0; i < cnt + 1; ++i)
                                    line += " ";
                                mod--;
                            }
                            else
                                for (int i = 0; i < cnt; ++i)
                                    line += " ";
                        }
                    }
                    result.push_back(line);
                    line = "";
                }
                lineWidth = 0;
            }
        }
        int lastLineSize = 0;
        while (q.size())
        {
            string str = q.front();
            q.pop();
            if (q.size())
            {
                line += str + " ";
                lastLineSize += str.size() + 1;
            }
            else
            {
                line += str;
                lastLineSize += str.size();
            }
        }
        int lastLineSpaces = maxWidth - lastLineSize;
        for (int i = 0; i < lastLineSpaces; ++i)
            line += " ";
        result.push_back(line);
        line = "";
        return result;
    }
};