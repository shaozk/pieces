// 211.添加与搜索单词-数据结构设计
//
// 请你设计一个数据结构，支持 添加新单词 和 查找字符串是否与任何先前添加的字符串匹配 。
// 实现词典类 WordDictionary ：
// * WordDictionary() 初始化词典对象
// * void addWord(word) 将 word 添加到数据结构中，之后可以对它进行匹配
// * bool search(word) 如果数据结构中存在字符串与 word 匹配，则返回 true ；否则，返回  false 。word 中可能包含一些 '.' ，每个 . 都可以表示任何一个字母。

class Trie {
public:
    vector<Trie*> children;
    bool isEnd;

    Trie() : children(26), isEnd(false) {}
    
    void addWord(string word) {
        Trie* dict = this;
        for (char ch : word) {
            ch -= 'a';
            if (!dict->children[ch]) {
                dict->children[ch] = new Trie();
            }
            dict = dict->children[ch];
        }
        dict->isEnd = true;
    }
};

class WordDictionary {
public:
    Trie* trie;

    WordDictionary() {
        this->trie = new Trie();
    }
    
    void addWord(string word) {
        trie->addWord(word);
    }

    bool dfs(const string& word, int index, Trie* node) {
        if (index == word.size()) return node->isEnd;
        char ch = word[index];
        if (ch >= 'a' && ch <= 'z') {
            Trie* child = node->children[ch - 'a'];
            if (child && dfs(word, index + 1, child)) return true;
        } else if (ch == '.') {
            for (int i = 0; i < 26; ++i) {
                Trie* child = node->children[i];
                if (child && dfs(word, index + 1, child)) return true;
            }
        }
        return false;
    }
    
    bool search(string word) {
        return dfs(word, 0, this->trie);
    }
};


