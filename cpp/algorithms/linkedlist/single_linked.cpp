// Copyright (c) 2020 Baidu.com, Inc. All Rights Reserved
// File Name: single_linked.cpp
// Author: fangxiaoming01@baidu.com 
// Created Time: Sun 10 May 2020 01:16:18 PM CST

#include <iostream>
using namespace std;

struct node {
    int val;
    node* next;

    node() {}
    node(int arg) : val(arg), next(NULL) {}
};

class LinkedList {
public:
    LinkedList() {
        size = 0;
        head = new node; // 只是头指针，不是第一个元素
    }

public:
    void add_at_head(int arg) { 
        node* p_node = new node(arg);
        p_node->next = head->next; // 节点拼接上 
        head->next = p_node; // 更换头节点
        size++;
    }

    void add_at_tail(int arg) {
        node* p_node = new node(arg);
        
        node* p_tmp = head;
        int index = size;
        while (index != 0) { // 单链表，从头遍历找到尾节点
            p_tmp = p_tmp->next;
            --index;
        }

        p_tmp->next = p_node;
        p_node->next = NULL;
        size++;
    }

    void add_by_index(int index, int arg) {
        if (index > size || index < 0) return;
        if (index == size) {
            add_at_tail(arg);
            return;
        }

        if (index == 0) {
            add_at_head(arg);
            return;
        }

        node* p_node = new node(arg);
        node* p_tmp = head;
        while (index != 0) { // 单链表，从头遍历找到尾节点
            p_tmp = p_tmp->next;
            --index;
        }

        p_node->next = p_tmp->next; // ?
        p_tmp->next = p_node;
        size++;
    }

    int get_by_index(int index) {
        if (index >= size || index < 0) return -1;
        node* p_tmp = head;
        while (index != -1) { // 单链表，从头遍历找到尾节点, 注意这里是判断到 -1
            p_tmp = p_tmp->next;
            --index;
        }

        return p_tmp->val;
    }

    void delete_by_index(int index) {
        if (index >= size || index < 0) return;
        node* p_tmp = head;
        while (index != 0) {
            p_tmp = p_tmp->next;
            --index;
        }
        node* delete_node = p_tmp->next; // 待删除节点
        p_tmp->next = p_tmp->next->next; // 重新链接
        size--;
        delete delete_node;
    }

    void print() {
        cout << "linked list:";
        node* p_node = head;
        int index = size;
        while(index != 0) {
            p_node = p_node->next;
            cout << p_node->val << " ";
            --index;
        }
        cout << endl;
    }

public:
    node* head;
    int size;

};


int main() {
    LinkedList my_link;
 
    my_link.add_at_head(5);
    my_link.add_at_head(3);
    my_link.add_at_head(8);

    cout << my_link.size << endl; 
    my_link.print();

    my_link.add_at_tail(10);
    my_link.add_at_tail(12);
    cout << my_link.size << endl;
    my_link.print();

    my_link.add_by_index(0, 101);
    my_link.print();

    my_link.add_by_index(my_link.size, 102);
    my_link.print();

    my_link.add_by_index(3, 103);
    my_link.print();

    cout << my_link.get_by_index(3) << endl;

    my_link.delete_by_index(3);
    my_link.print();

    return 0;
}
