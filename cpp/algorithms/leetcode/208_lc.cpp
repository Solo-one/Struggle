// Copyright (c) 2020 fxm.com, Inc. All Rights Reserved
// File Name: 208_lc.cpp
// Author: fangxiaoming01@baidu.com 
// Created Time: Thu 09 Jul 2020 09:27:42 AM CST

#include <iostream>
using namespace std;

// 自定义前缀树
class Trie {
private:
    bool isEnd;
    Trie* next[26]; // 这里模拟[a-z]字母

public:
    void insert(string word) {
        Trie* node = this;

        for (int i = 0; i < word.length(); ++i) {
            char ch = word[i];
            if (node->next[ch-'a'] == NULL) { // 没有元素，就新建节点
                node->next[ch-'a'] = new Trie();
            }
            node = node->next[ch-'a']; // 指向下一个节点 
        }

        node->isEnd = true; // 最后一个节点，true
    }

    bool search(string word) {
        Trie* node = this;

        // C++11支持
        for (char ch : word) {
            node = node->next[ch-'a'];
            if (node == NULL) {
                return false;
            }
        }

        return node->isEnd; // 可能是word前缀部分
    }

    bool startsWith(string prefix) {
        Trie* node = this;
        // C++11支持
        for (char ch : prefix) {
            node = node->next[ch-'a'];
            if (node == NULL) {
                return false;
            }
        }

        return true;
    }

};

int main(int argc, char* argv[]) {
    Trie* trie = new Trie();
    
    cout << true << endl;
    cout << false << endl;

    trie->insert("apple");
    cout << trie->search("apple") << endl;  // 返回 true
    cout << trie->search("app") << endl;     // 返回 false
    cout << trie->startsWith("app") << endl; // 返回 true
    cout << trie->startsWith("appe") << endl; // 返回 false

    trie->insert("app");
    cout << trie->search("app") << endl;     // 返回 true
    
    delete trie;

    return 0;
}
