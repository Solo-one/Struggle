// Copyright (c) 2020 Baidu.com, Inc. All Rights Reserved
// File Name: linked_stack.cpp
// Author: fangxiaoming01@baidu.com 
// Created Time: Fri 08 May 2020 03:12:07 PM CST

#include <iostream>
using namespace std;

struct node {
    int value;
    node* next;
    node() : next(nullptr){}
    node(int t) : value(t), next(nullptr){}
};

class Stack {
    public:
        Stack() {
            length = 0;
            head = new node;
        }

        ~Stack() {
            if (head != nullptr) {
                delete head;
                head = nullptr;
            }
        }

        int push(int arg);
        int pop();
        int top();

        int size();
        bool empty();

    private:
        int length;
        node* head;
};

int Stack::push(int arg) {
    node* p_node = new node(arg);
    p_node->next = head->next; // 核心，这里
    head->next = p_node; // 作为新的栈顶
    length++;
    
    cout << "push:" << p_node->value << ";length:" << length << endl;
    return 0;
}

int Stack::pop() {
    if (head->next != nullptr) {
        node* p_node = head->next;
        int value = p_node->value;
        head->next = p_node->next;
        delete p_node; // 出栈释放内存
        length--;
        return value;
    }
}

int Stack::top() {
    if (head->next != nullptr) {
        return head->next->value;
    }
}

int Stack::size() {
    return length;
}

bool Stack::empty() {
    return length == 0;
}


/**
 *  基于链表建立的栈, 理论栈长度受限于内存大小
 *
 */
int main() {
    Stack mystack;
    mystack.push(1);
    mystack.push(8);
    mystack.push(1);
    mystack.push(6);

    cout << "pop:" << mystack.pop() << endl;
    cout << "length:" << mystack.size() << endl;

    cout << "top:" << mystack.top() << endl;

    return 0;
}
