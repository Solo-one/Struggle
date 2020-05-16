// Copyright (c) 2020 fxm.com, Inc. All Rights Reserved
// File Name: 20_lc.cpp
// Author: fangxiaoming01@baidu.com 
// Created Time: Sat 16 May 2020 10:21:49 PM CST

#include <iostream>
#include <stack>
using namespace std;

//20. 有效的括号

bool isValid(string s) {
    stack<char> store;
    if (s.size() % 2 == 1) {
        return false; // 奇数直接返回
    }

    for (int i=0; i<s.size(); ++i) {
        char tmp = ' ';
        switch(s[i]) {
            case '(':
            case '{':
            case '[':
                store.push(s[i]);
                break;
            case ')':
                if (store.empty()) {
                    return false;
                }
                tmp = store.top();
                store.pop();
                if (tmp != '(') {
                    return false;
                }
                break;

            case ']':
                if (store.empty()) {
                    return false;
                }
                tmp = store.top();
                store.pop();
                if (tmp != '[') {
                    return false;
                }
                break;

            case '}':
                if (store.empty()) {
                    return false;
                }
                tmp = store.top();
                store.pop();
                if (tmp != '{') {
                    return false;
                }
                break;
            default:
                return false;
                break;
        }
    }

    if (store.empty()) {
        return true;
    } else {
        return false;
    }
}


int main() {

    return 0;
}
