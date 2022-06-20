

/*


https://www.codingninjas.com/codestudio/problems/implement-trie_1387095?utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_tries_videos&leftPanelTab=0

*/
struct Node {
    Node* links[26];
    int cntEndsWith = 0;
    int cntPrefix = 0;

    bool containsKey(char ch) {
        return (links[ch - 'a'] != NULL);
    }
    Node* get (char ch) {
        return links[ch - 'a'];
    }
    int getPrefix() {
        return cntPrefix;
    }

    void put(char ch , Node* node) {
        links[ch - 'a'] = node;
    }

    int getEnd() {
        return cntEndsWith;
    }

    void increaseEnd() {
        cntEndsWith++;
    }
    void increasePrefix() {
        cntPrefix++;
    }
    void deleteEnd() {
        cntEndsWith--;
    }
    void reducePrefix() {
        cntPrefix--;
    }
};




class Trie {
private:
    Node* root;
public:

    Trie() {
        // Write your code here.
        root = new Node();
    }

    void insert(string &word) {
        // Write your code here.
        Node* node = root ;
        for (int i = 0 ; i < word.size(); i++) {
            char ch = word[i];
            if (!node->containsKey(ch)) {
                node->put(ch, new Node());
            }
            node = node->get(ch);
            node->increasePrefix();
        }
        node->increaseEnd();
    }

    int countWordsEqualTo(string &word) {
        // Write your code here.
        Node* node = root ;
        for (int i = 0 ; i < word.size(); i++) {
            char ch = word[i];
            if (node->containsKey(ch)) {
                node = node->get(ch);
            }
            else
                return 0;
        }
        return node->getEnd();
    }

    int countWordsStartingWith(string &word) {
        // Write your code here.
        Node* node = root ;
        for (int i = 0 ; i < word.size(); i++) {
            char ch = word[i];
            if (node->containsKey(ch)) {
                node = node->get(ch);
            }
            else {
                return 0;
            }
        }
        return node->getPrefix();
    }

    void erase(string &word) {
        // Write your code here.
        Node* node = root ;
        for (int i = 0 ; i < word.size(); i++) {
            char ch = word[i];
            if (node->containsKey(ch)) {
                node = node->get(ch);
                node->reducePrefix();

            }
            else {
                return ;
            }
        }
        node->deleteEnd();


    }
};
