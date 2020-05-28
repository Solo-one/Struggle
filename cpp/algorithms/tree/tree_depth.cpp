// Copyright (c) 2020 fxm.com, Inc. All Rights Reserved
// File Name: tree_depth.cpp
// Author: fangxiaoming01@baidu.com 
// Created Time: Thu 14 May 2020 04:49:09 PM CST

#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int arg) : val(arg), left(NULL), right(NULL) {}
};

// 104、二叉树的最大深度  
int max_depth(TreeNode* root) {
    if (root == NULL) return 0;

    int left_height = max_depth(root->left);
    int right_height = max_depth(root->right);

    return Math.max(left_height, right_height) + 1;

}

int main() {

    return 0;
}
