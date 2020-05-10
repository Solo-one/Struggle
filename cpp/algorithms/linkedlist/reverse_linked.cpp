// Copyright (c) 2020 Baidu.com, Inc. All Rights Reserved
// File Name: reverse_linked.cpp
// Author: fangxiaoming01@baidu.com 
// Created Time: Sun 10 May 2020 08:14:21 PM CST

#include <iostream>
#include "single_linked.h"
using namespace std;

// ����
node* reverse_linked(node* head) {
    node* prev = head;
    node* curr = NULL;
    while (prev != NULL) {
        node* temp_next = prev->next;

        prev->next = curr; // �ı�ָ����

        curr = prev; // ǰ��
        prev = temp_next; // ǰ��
    }

    return curr;
}

// �ݹ�
node* reverse_linked_1(node* head) {
    // �ݹ��˳�����
    if (head == NULL || head->next == NULL) {
        return head;
    }
    node* ret = reverse_linked_1(head->next);
    head->next->next = head; // �ı�ָ����
    head->next = NULL;
    return ret;
}

int main() {
    LinkedList my_link;
 
    my_link.add_at_head(5);
    my_link.add_at_head(3);
    my_link.add_at_head(8);
    my_link.add_at_tail(10);
    my_link.add_at_tail(12);
    cout << my_link.size << endl;
    my_link.print();

    my_link.print(my_link.head);
    //my_link.print(reverse_linked(my_link.head));
    my_link.print(reverse_linked_1(my_link.head->next));

    return 0;
}
