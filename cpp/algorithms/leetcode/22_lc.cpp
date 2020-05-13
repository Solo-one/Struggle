// Copyright (c) 2020 fxm.com, Inc. All Rights Reserved
// File Name: 22_lc.cpp
// Author: fangxiaoming01@baidu.com 
// Created Time: Tue 12 May 2020 11:43:54 PM CST

/**
 * 24. 两两交换链表中的节点
 */

#include <iostream>
using namespace std;

struct node {
    int val;
    node* next;
    node(int arg) : val(arg), next(NULL) {}
};

// 递归方法
node* swap_pairs(node* head) {

    // 终止条件为所有都交换完了的链表
    if (head == NULL || head->next == NULL) {
        return head;
    }

    node* p = head->next;
    node* temp = head->next->next;

    p->next = head;

    // 换完成后的head应指向下一次单元返回的头节点
    head->next = swap_pairs(temp);

    return p;
}

int main() {

    return 0;
}
