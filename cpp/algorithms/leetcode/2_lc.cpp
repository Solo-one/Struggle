// Copyright (c) 2020 fxm.com, Inc. All Rights Reserved
// File Name: 2_lc.cpp
// Author: fangxiaoming01@baidu.com 
// Created Time: Sat 16 May 2020 11:22:41 AM CST

#include <iostream>
using namespace std;

/**
 * 2. 两数相加
 */
struct node {
    int val;
    node* next;
    node(int arg) : val(arg), next(NULL) {}
};

node* addTwoNumbers(node* l1, node* l2) {
    int carry = 0;
    int sum = 0;

    node newhead(0);
    node* node = &newhead;

    while ((l1 != NULL) || (l2 != NULL) || carry != 0) {
        sum = carry;
        sum += l1 ? l1->val : 0;
        sum += l2 ? l2->val : 0;

        carry = sum / 10;

        //该位的值等于 sum 与 10 取余
        node->next = new node(sum % 10);
        node = node->next;

        l1 = l1 ? l1->next : l1;
        l2 = l2 ? l2->next : l2;
    }

    return newhead.next;
}

int main() {

    return 0;
}
