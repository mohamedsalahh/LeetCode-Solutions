class Node
{
public:
    char val;
    bool isWord = false;
    Node *left, *right, *mid;
    Node(char _val, Node *_left, Node *_mid, Node *_right, bool _isWord) : val(_val), left(_left), mid(_mid), right(_right), isWord(_isWord) {}
};
class Trie
{
private:
    Node *root;
    bool _search(Node *_root, string word, int idx = 0)
    {
        if (_root == NULL)
            return false;

        if (word[idx] > _root->val)
            return _search(_root->right, word, idx);
        else if (word[idx] < _root->val)
            return _search(_root->left, word, idx);
        else
        {
            if (idx == word.size() - 1)
                return _root->isWord;
            else
                return _search(_root->mid, word, idx + 1);
        }
    }
    Node *_insert(Node *_root, string word, int idx = 0)
    {
        if (_root == NULL)
        {
            _root = new Node(word[idx], 0, 0, 0, 0);
            if (idx == word.size() - 1)
                _root->isWord = true;
            else
                _root->mid = _insert(_root->mid, word, idx + 1);
        }

        else
        {
            if (word[idx] > _root->val)
                _root->right = _insert(_root->right, word, idx);
            else if (word[idx] < _root->val)
                _root->left = _insert(_root->left, word, idx);
            else
            {
                if (idx == word.size() - 1)
                    _root->isWord = true;
                else
                    _root->mid = _insert(_root->mid, word, idx + 1);
            }
        }
        return _root;
    }

    bool _startWith(Node *_root, string word, int idx = 0)
    {
        if (_root == NULL)
            return false;

        if (word[idx] > _root->val)
            return _startWith(_root->right, word, idx);
        else if (word[idx] < _root->val)
            return _startWith(_root->left, word, idx);
        else
        {
            if (idx == word.size() - 1)
                return true;
            else
                return _startWith(_root->mid, word, idx + 1);
        }
    }

public:
    Trie()
    {
        root = NULL;
    }

    void insert(string word)
    {
        root = _insert(root, word);
    }

    bool search(string word)
    {
        return _search(root, word);
    }

    bool startsWith(string prefix)
    {
        return _startWith(root, prefix);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */