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
        head = new node; // ֻ��ͷָ�룬���ǵ�һ��Ԫ��
    }

public:
    void add_at_head(int arg) { 
        node* p_node = new node(arg);
        p_node->next = head->next; // �ڵ�ƴ���� 
        head->next = p_node; // ����ͷ�ڵ�
        size++;
    }

    void add_at_tail(int arg) {
        node* p_node = new node(arg);
        
        node* p_tmp = head;
        int index = size;
        while (index != 0) { // ��������ͷ�����ҵ�β�ڵ�
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
        while (index != 0) { // ��������ͷ�����ҵ�β�ڵ�
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
        while (index != -1) { // ��������ͷ�����ҵ�β�ڵ�, ע���������жϵ� -1
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
        node* delete_node = p_tmp->next; // ��ɾ���ڵ�
        p_tmp->next = p_tmp->next->next; // ��������
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

    void print(node* head) {
        node* p_node = head;
        while (p_node != NULL && p_node->next != NULL) {
            p_node = p_node->next; 
            cout << p_node->val << " ";
        }
        cout << endl;
    }

public:
    node* head;
    int size;
};

