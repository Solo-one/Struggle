// Copyright (c) 2018 Baidu.com, Inc. All Rights Reserved
// File Name: myStack.cpp
// Author: fangxiaoming01@baidu.com 
// Created Time: 2018年08月09日 星期四 23时26分20秒

#include<iostream>
#include<vector>
#include<stdexcept>
using namespace std;

// 基于动态数组模板实现，也可以使用固定长度数组（入栈时需要判断数组是否满）
template <class T>
class myStack {
    public:
        void push(T const&);
        void pop();
        T top() const;
        int size() const;
        bool empty() const {
            return _elems.empty();
        }

    private:
        vector<T> _elems;
};

template <class T>
void myStack<T>::push(T const& elems) {
    _elems.push_back(elems);
}

template <class T>
void myStack<T>::pop() {
    if (empty()) {
        throw out_of_range("Stack<>::pop(): empty stack");
    }
    _elems.pop_back();
}

template <class T>
T myStack<T>::top() const {
    if (empty()) {  
        throw out_of_range("Stack<>::pop(): empty stack");
    }
    return _elems.back(); // 返回最后一个元素
}

template <class T>
int myStack<T>::size() const {
    return _elems.size();
}

int main() {
    try {
        myStack<int> intStack;
        myStack<string> stringStack;
    
        intStack.push(9);
        intStack.push(19);
        intStack.push(10);
        intStack.push(100);

        cout << "size:" << intStack.size() << endl;
        cout << intStack.top() << endl;

    } catch (exception const& ex) {
        cerr << "Exception:" << ex.what() << endl;
    }

    return 0;
}
