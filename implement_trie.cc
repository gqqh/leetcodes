//实现一个trie树，支持insert,search,startsWith方法
//假设所有的单词都是小写字母[a-z]
//思想很简单，就是每个节点都包含若干个next分支，如果有对应字母，
// 则相应分支的next不为空，否则为空，在最后一个字母的next->is_word == true;
//只包含“hello”的trie树
//root{false, next['h']}--h-->{false, next['e']}--e--{false, next['l']}--l--
//      {false, next['l']}--l--{false, next['o']}--o--{true, next=NULL}
//加一个"he"，变成
//root{false, next['h']}--h-->{false, next['e']}--e--{true, next['l']}--l--
//      {false, next['l']}--l--{false, next['o']}--o--{true, next=NULL}

#include <iostream>
#include <string>

using namespace std;

#define  NUM_CHAR 26

class TrieNode {
public:
    TrieNode *next[NUM_CHAR]; //下面的节点
    bool is_word;      //表明该节点为止有多少个单词，0表示不是单词，1表示一个
    // Initialize your data structure here.
    TrieNode() {
        is_word = false;
        for(int i = 0; i < NUM_CHAR; i++)
            next[i] = NULL;
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }
    ~Trie(){
        delete root;
    }

    // Inserts，从第一个字母往后依次插入,如果没有则创建，否则直接往下走，
    // 把最后一个节点的标志置为true，注意如果插入重复的单词，是分辨不出来的
    void insert(string word) {
        if(root == NULL || word.empty())
            return;
        TrieNode *p = root;
        for(int i = 0, len = word.size(); i < len; i++){
            if(p->next[word[i]-'a'] == NULL){
                TrieNode * tmp = new TrieNode();
                p->next[word[i]-'a'] = tmp;
            }
            p = p->next[word[i]-'a'];
        }
        p->is_word = true;
    }

    // 在trie树中找word
    bool search(string word) {
        TrieNode *p = root, *tmp;
        int i = 0;
        int len = word.size();
        while(p != NULL && i < len)
            p = p->next[word[i++]-'a'];

        if(p == NULL){
            return false;
        }else{
            return p->is_word;
        }
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode *p = root, *tmp;
        int i = 0;
        int len = prefix.size();
        while(p != NULL && i < len)
            p = p->next[prefix[i++]-'a'];

        if(p == NULL){
            return false;
        }else{
            return true;
        }
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");
