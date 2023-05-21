/*
    Your Trie object will be instantiated and called as such:
    Trie* obj = new Trie();
    obj->insert(word);
    bool check2 = obj->search(word);
    bool check3 = obj->startsWith(prefix);
 */

#include<string>

class TrieNode{
    public:
    char data;
    TrieNode* children;
    bool isTerminal;

    TrieNode(char data){
        this->data = data;
        children = new TrieNode*[26];

        for(int i=0; i<26; i++){
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie {
    TrieNode* root;
public:

    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode('\0');

    }

    void insert(TrieNode* root, string word) {
        if(word.size() == 0){
            root->isTerminal = true;
            return;
        }
        int index = word[0] - 'a';
        TrieNode* child;
        if(root->children[index] != NULL){
            child = root->children[index];
        }
        else{
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }
        insert(child, word.substr(1));
    }
    void insert(string word){
        insert(root, word);
    }
    bool search(TrieNode* root, string word) {
        if(word.size() == 0){
            return root->isTerminal;
        }
        int index = word[0] - 'a';
        TrieNode* child;
        if(root->children[index] == NULL){
            return false;
        }
        child = root->children[index];
        return search(child, word.substr(1));
    }
    bool search(string word){
        return search(root, word);
    }
    bool startsWith(TrieNode* root, string prefix) {
        if(prefix.size() == 0){
            return true;
        }

        int index = prefix[0] - 'a';
        TrieNode* child;

        if(root->children[index] == NULL){
            return false;
        }

        child = root->children[index];
        return startsWith(child, prefix.substr(1));
    }
    bool startsWith(string prefix){
        return startsWith(root, prefix);
    }
    
};