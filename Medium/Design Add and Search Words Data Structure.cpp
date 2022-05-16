class Node
{
public:
    bool isWord = false;
    vector<Node *> children = vector<Node *>(26, NULL);
};
class WordDictionary
{
private:
    Node *root;
    void _insert(Node *_root, string word, int idx = 0)
    {
        if (_root->children[word[idx] - 'a'] == NULL)
            _root->children[word[idx] - 'a'] = new Node;

        if (idx == word.size() - 1)
        {
            _root->children[word[idx] - 'a']->isWord = true;
            return;
        }
        _insert(_root->children[word[idx] - 'a'], word, idx + 1);
    }
    bool _search(Node *_root, string word, int idx = 0)
    {
        if (word[idx] == '.')
        {
            if (idx == word.size() - 1)
            {
                for (auto child : _root->children)
                {
                    if (child == NULL)
                        continue;
                    if (child->isWord)
                        return true;
                }
                return false;
            }
            for (auto child : _root->children)
            {
                if (child == NULL)
                    continue;
                if (_search(child, word, idx + 1))
                    return true;
            }
            return false;
        }
        else
        {
            if (_root->children[word[idx] - 'a'] != NULL)
            {
                if (idx == word.size() - 1)
                    return _root->children[word[idx] - 'a']->isWord;
                return _search(_root->children[word[idx] - 'a'], word, idx + 1);
            }
            else
                return false;
        }
        return true;
    }

public:
    WordDictionary()
    {
        root = new Node;
    }

    void addWord(string word)
    {
        _insert(root, word);
    }

    bool search(string word)
    {
        return _search(root, word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */