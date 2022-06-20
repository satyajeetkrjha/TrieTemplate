
/*

https://www.codingninjas.com/codestudio/problems/count-distinct-substrings_985292?utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_tries_videos&leftPanelTab=0
*/

struct Node {
    Node* links[26];
    bool flag = false;

    bool containsKey(char ch) {
        return links[ch - 'a'] != NULL;
    }
    Node* get(char ch) {
        return links[ch - 'a'];
    }

    Node* put(char ch , Node* node) {
        links[ch - 'a'] = node;
    }

    void setEnd() {
        flag = true;
    }

    bool isEnd() {
        return flag ;
    }

};


int countDistinctSubstrings(string &s)
{

    Node *root = new Node();
    int count = 0 ;
    for (int i = 0 ; i < s.size(); i++) {
        Node* node = root ;
        for (int j = i; j < s.size(); j++) {
            char ch = s[j];
            if (!node->containsKey(ch)) {
                node->put(ch, new Node());
                count++;
            }
            node = node->get(ch);
        }
    }

    return count + 1;
}