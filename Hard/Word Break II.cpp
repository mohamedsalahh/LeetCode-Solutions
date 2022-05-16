class Node
{
public:
    bool isWord = false;
    map<char, Node *> children;
};
class Trie
{
private:
    Node *root;
    void _insert(Node *_root, string word, int idx = 0)
    {
        if (_root->children[word[idx]] == NULL)
            _root->children[word[idx]] = new Node;

        if (idx == word.size() - 1)
        {
            _root->children[word[idx]]->isWord = true;
            return;
        }
        _insert(_root->children[word[idx]], word, idx + 1);
    }

    bool _search(Node *_root, string word, int idx = 0)
    {
        if (_root->children[word[idx]] != NULL)
        {
            if (idx == word.size() - 1)
                return _root->children[word[idx]]->isWord;
            return _search(_root->children[word[idx]], word, idx + 1);
        }
        else
            return false;
    }

public:
    Trie() : root(new Node) {}
    void insert(string word)
    {
        _insert(root, word);
    }
    bool search(string word)
    {
        return _search(root, word);
    }
};

class Solution
{
public:
    void find(string s, string sentence, vector<string> &ans, Trie &t)
    {
        for (int i = 0; i <= s.size(); ++i)
        {
            string ss = s.substr(0, i);
            if (t.search(ss))
            {
                if (i == s.size())
                {
                    ans.push_back(sentence + ss);
                    return;
                }
                find(s.substr(i), sentence + ss + " ", ans, t);
            }
        }
    }
    vector<string> wordBreak(string s, vector<string> &wordDict)
    {
        Trie t;
        for (string word : wordDict)
            t.insert(word);
        vector<string> ans;
        find(s, "", ans, t);
        return ans;
    }
};