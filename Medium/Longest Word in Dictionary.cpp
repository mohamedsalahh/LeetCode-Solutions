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
    void _findLongestWord(Node *_root, string &word, string &ans)
    {
        for (auto child : _root->children) // children are sorted
        {
            if (child.second == NULL)
                continue;

            if (child.second->isWord)
            {
                word.push_back(child.first);

                if (word.size() > ans.size())
                    ans = word;

                _findLongestWord(child.second, word, ans);
                word.pop_back();
            }
        }
    }

public:
    Trie() : root(new Node) {}
    void insert(string word)
    {
        _insert(root, word);
    }
    string findLongestWord()
    {
        string ans = "", word = "";
        _findLongestWord(root, word, ans);
        return ans;
    }
};
class Solution
{
public:
    string longestWord(vector<string> &words)
    {
        Trie trie;
        for (string word : words)
            trie.insert(word);
        return trie.findLongestWord();
    }
};