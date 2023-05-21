#include <bits/stdc++.h> 
class Node{
    public:
    char data;
    Node* child[26];
    int wordEnd;
    int wordCount;
    Node(char data){
        wordEnd=0;
        wordCount=0;
        this->data=data;
        for(int i=0;i<26;i++){
            child[i]=NULL;
        }
    }
};
class Trie{

    public:
    Node* root;

    Trie() {
    root=new Node('/');  
    }

    void insert(string word) {
        Node * curr=root;
        for(int i=0;i<word.length();i++){
            int ind=word[i]-'a';
            if(curr->child[ind]==NULL){
                curr->child[ind]=new Node(word[i]);
            }
            curr=curr->child[ind];
                curr->wordCount++;
        }  curr->wordEnd++; 
    }

    int countWordsEqualTo(string &word){
        Node* curr=root;
        for(int i=0;i<word.length();i++){
            int ind=word[i]-'a';
            if(!curr->child[ind] || curr->child[ind]->wordCount<=0)return 0;
            curr=curr->child[ind];
        }
       return curr->wordEnd;
    }

    int countWordsStartingWith(string &word){
        Node* curr=root;
        for(int i=0;i<word.length();i++){
            int ind=word[i]-'a';
            if(curr->child[ind]==NULL || curr->child[ind]->wordCount<=0)return 0;
            curr=curr->child[ind];
        }
        return curr->wordCount;
    }

    void erase(string &word){
        Node* curr=root;
        for(int i=0;i<word.length();i++){
            int ind=word[i]-'a';
                curr=curr->child[ind];
            curr->wordCount--;
        }
        curr->wordEnd--;
        
    }
};