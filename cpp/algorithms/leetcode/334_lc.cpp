// Copyright (c) 2020 fxm.com, Inc. All Rights Reserved
// File Name: 334_lc.cpp
// Author: fangxiaoming01@baidu.com 
// Created Time: Tue 12 May 2020 10:58:02 PM CST

/**
 * 344. 反转字符串
 */

#include <iostream>
using namespace std;

// 循环
void reverse_string(std::string ss) {
    //ss[2] = 'a';
    cout << ss << endl; 
    
    if (ss == "") return;

    for (int i=0; i<ss.size()/2; ++i) {
        char tmp = ss[i];
        ss[i] = ss[ss.size()-1 - i];
        ss[ss.size()-1 - i] = tmp;
    }

    cout << ss << endl; 
}

// 双指针方法
void reverse_string1(std::string ss) {
    if (ss == "") return;

    int start = 0;
    int end = ss.size()-1;

    while (start<end) {
        char tmp = ss[start];
        ss[start] = ss[end];
        ss[end] = tmp;
        start++;
        end--;
    }

    cout << ss << endl; 
}

// 递归
void reverse_string2(std::string& ss, int pos, int length) {
    if (ss == "") return;

    if (pos >= length/2) return; // 递归终止条件
    
    char tmp = ss[pos];
    ss[pos] = ss[length-1-pos];
    ss[length-1-pos] = tmp;

    reverse_string2(ss, pos+1, length);

    cout << ss << endl; 
}


int main() {
    std::string ss = "abcdef";
    cout << ss << endl; 
    //reverse_string(ss);
    //reverse_string1(ss);

    reverse_string2(ss, 0, ss.size());
    return 0;
} 
