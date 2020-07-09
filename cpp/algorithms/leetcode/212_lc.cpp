// Copyright (c) 2020 fxm.com, Inc. All Rights Reserved
// File Name: 212_lc.cpp
// Author: fangxiaoming01@baidu.com 
// Created Time: Thu 09 Jul 2020 07:33:00 PM CST

#include <iostream>
#include <vector>
using namespace std;

struct TrieNode {
    string word;
    vector<TrieNode*> nodes;

    TrieNode() : word("") {
        nodes.resize(26, 0);
    }
};

class Solution {
public:
    int rows, cols;
    vector<string> res;

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        rows = board.size();
        cols = rows > 0 ? board[0].size() : 0;
        if (rows == 0 || cols == 0) return res;

        // 建立字典树的模板 
        TrieNode* root = new TrieNode();
        for (string word: words) {
            TrieNode* cur = root;
            for (char ch: word) {
                if (cur->nodes[ch-'a'] == 0) {
                    cur->nodes[ch-'a'] = new TrieNode();
                }

                cur = cur->nodes[ch-'a'];
            }
            cur->word = word;
        }
    
        // DFS模板
        for(int i = 0; i < rows; ++i){
            for(int j = 0; j < cols; ++j){
                dfs(board, root, i, j);
            }
        }

        return res;
    }

    void dfs(vector<vector<char>>& board, TrieNode* root, int x, int y) {
        char c = board[x][y];
        if(c=='.' || root->nodes[c-'a']==0) return;
        root = root->nodes[c-'a'];
        if(root->word!=""){
            res.push_back(root->word);
            root->word = "";
        }

        board[x][y] = '.';
        if(x>0) dfs(board, root, x-1, y);
        if(y>0) dfs(board, root, x, y-1);
        if(x+1<rows) dfs(board, root, x+1, y);
        if(y+1<cols) dfs(board, root, x, y+1);
        board[x][y] = c;
    }
};

int main(int argc, char** argv) {
    std::string word = ""; 

    return 0;
}
