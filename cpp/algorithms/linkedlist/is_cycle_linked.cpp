// Copyright (c) 2020 Baidu.com, Inc. All Rights Reserved
// File Name: is_cycle_linked.cpp
// Author: fangxiaoming01@baidu.com 
// Created Time: Sun 10 May 2020 07:51:17 PM CST

#include <iostream>
using namespace std;

struct node {
    int val;
    node* next;
    node() {}
    node(int arg) : val(arg), next(NULL) {}
};

// 参数为链表头指针，类似数组第一个元素
bool is_cycle_linked(node* head) {
    if (head == NULL || head->next == NULL) {
        return false;
    }
    
    node* faster = head;
    node* slower = head;

    while (faster != NULL && faster->next != NULL) {
        faster = faster->next->next; // 走2步
        slower = slower->next; // 走1步

        if (faster == slower) { // 有相等情况，说明有环
            return true;
        }
    }
   
    return false;
}

int main() {
    
    return 0;
}
