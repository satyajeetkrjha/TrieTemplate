/*
    Your Trie object will be instantiated and called as such:
    Trie* obj = new Trie();
    obj->insert(word);
    bool check2 = obj->search(word);
    bool check3 = obj->startsWith(prefix);
 */

//https://www.codingninjas.com/codestudio/problems/implement-trie_631356

struct Node {
    Node* links[26];
    bool flag = false;
    bool containsKey(char ch) {
        return (links[ch - 'a'] != NULL);
    }
    void put( char ch , Node* node) {
        links[ch - 'a'] = node;
    }
    Node* get(char ch) {
        return links[ch - 'a'];
    }
    void setEnd() {
        flag = true;
    }
    bool isEnd() {
        return flag;
    }
};


class Trie {
private :
    Node* root ;
public:

    /** Initialize your data structure here. */
    Trie() {
        root = new Node();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        Node* node = root ;
        for (int i = 0 ; i < word.size(); i++) {
            char ch = word[i];
            if (!node->containsKey(ch)) {
                node->put(ch, new Node());
            }
            node = node->get(ch);

        }
        node->setEnd();
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node* node = root ;
        for (int i = 0 ; i < word.size(); i++) {
            char ch = word[i];
            if (!node->containsKey(ch)) {
                return false;
            }
            node = node->get(ch);
        }
        return node->isEnd() == true ? true : false;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node* node = root ;
        for (int i = 0 ; i < prefix.size(); i++) {
            char ch = prefix[i];
            if (!node->containsKey(ch)) {
                return false;
            }
            node = node->get(ch);
        }
        return true ;
    }
};