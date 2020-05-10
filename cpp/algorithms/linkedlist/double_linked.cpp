// Copyright (c) 2020 Baidu.com, Inc. All Rights Reserved
// File Name: double_linked.cpp
// Author: fangxiaoming01@baidu.com 
// Created Time: Sun 10 May 2020 09:37:10 PM CST

#include <iostream>
using namespace std;

struct node {
    int val;
    node *next, *prev;

    node() {}
    node(int arg) : val(arg), next(NULL), prev(NULL) {}
};

class LinkedList {
public:
    LinkedList() {
        size = 0;
        head = NULL;
        tail = NULL;
    }

public:
    void add_at_head(int arg) { 
        if (head == NULL) {
            head = new node(arg);
            tail = head;
        } else {
            node* p_node = new node(arg);
            p_node->next = head; // 节点拼接上 
            head->prev = p_node; // 更换头节点     
            head = p_node;
        } 
        size++;
    }

    void add_at_tail(int arg) {
        if (tail == NULL) {
            tail = new node(arg);
            head = tail;
        } else {
            node* p_node = new node(arg);
            p_node->prev = tail; // 节点拼接上 
            tail->next = p_node; // 更换头节点     
            tail = p_node;
        } 
        size++;   
    }

    void add_by_index(int index, int arg) {
    }

    void delete_by_index(int index) {
    }

public:
    node *head, *tail;
    int size;

};

int main() {

    return 0;
}
