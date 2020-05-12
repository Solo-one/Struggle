// Copyright (c) 2020 fxm.com, Inc. All Rights Reserved
// File Name: tree_traversal.cpp
// Author: fangxiaoming01@baidu.com 
// Created Time: Mon 11 May 2020 04:42:03 PM CST

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int arg) : val(arg), left(NULL), right(NULL) {}
};

// 二叉树前序遍历
vector<int> preorderTraversal(TreeNode* root) {
    std::stack<TreeNode*> stack;
    vector<int> vec;

    TreeNode* cur = root;
    while (cur != NULL || !stack.empty()) {
        while (cur != NULL) {
            stack.push(cur);
            vec.push_back(cur->val); // 注意这里
            cur = cur->left;
        }
        cur = stack.top();
        stack.pop();
        cur = cur->right;
    }

    return vec;
}

// 二叉树后续遍历
vector<int> postorderTraversal(TreeNode* root) {
    std::stack<TreeNode*> stack;
    vector<int> vec;

    TreeNode* cur = root;
    while (cur != NULL || !stack.empty()) {
        while (cur != NULL) {
            stack.push(cur);
            vec.push_back(cur->val); // 注意这里
            cur = cur->right;
        }
        cur = stack.top();
        stack.pop();
        cur = cur->left;
    }

    std::reverse(vec.begin(), vec.end()); // 相对前序反转

    return vec;
}


// 二叉树中序遍历
vector<int> inorderTraversal(TreeNode* root) {
    std::stack<TreeNode*> stack;
    vector<int> vec;

    TreeNode* cur = root;
    while (cur != NULL || !stack.empty()) {
        while (cur != NULL) {
            stack.push(cur);
            cur = cur->left;
        }
        cur = stack.top();
        stack.pop();
        vec.push_back(cur->val); // 注意这里
        cur = cur->right;
    }

    return vec;
}

// 二叉树层次遍历BFS
vector<vector<int> > levelOrder(TreeNode* root) {
    vector<vector<int> > ret;
    if (root == NULL) {
        return ret;
    }

    std::queue<TreeNode*> queue;
    queue.push(root);
    
    while (!queue.empty()) {
        vector<int> level; // 存放每一层的元素值
        int count = queue.size(); //队列大小表示当前层数的元素个数
        while (count--) {
            TreeNode* t = queue.front();
            queue.pop();
            level.push_back(t->val);
            if (t->left) {
                queue.push(t->left);
            }
            if (t->right) {
                queue.push(t->right);
            }
        }

        ret.push_back(level);
    }

    return ret;
}

int main() {

    return 0;
}
