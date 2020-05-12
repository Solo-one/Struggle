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

// ������ǰ�����
vector<int> preorderTraversal(TreeNode* root) {
    std::stack<TreeNode*> stack;
    vector<int> vec;

    TreeNode* cur = root;
    while (cur != NULL || !stack.empty()) {
        while (cur != NULL) {
            stack.push(cur);
            vec.push_back(cur->val); // ע������
            cur = cur->left;
        }
        cur = stack.top();
        stack.pop();
        cur = cur->right;
    }

    return vec;
}

// ��������������
vector<int> postorderTraversal(TreeNode* root) {
    std::stack<TreeNode*> stack;
    vector<int> vec;

    TreeNode* cur = root;
    while (cur != NULL || !stack.empty()) {
        while (cur != NULL) {
            stack.push(cur);
            vec.push_back(cur->val); // ע������
            cur = cur->right;
        }
        cur = stack.top();
        stack.pop();
        cur = cur->left;
    }

    std::reverse(vec.begin(), vec.end()); // ���ǰ��ת

    return vec;
}


// �������������
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
        vec.push_back(cur->val); // ע������
        cur = cur->right;
    }

    return vec;
}

// ��������α���BFS
vector<vector<int> > levelOrder(TreeNode* root) {
    vector<vector<int> > ret;
    if (root == NULL) {
        return ret;
    }

    std::queue<TreeNode*> queue;
    queue.push(root);
    
    while (!queue.empty()) {
        vector<int> level; // ���ÿһ���Ԫ��ֵ
        int count = queue.size(); //���д�С��ʾ��ǰ������Ԫ�ظ���
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
