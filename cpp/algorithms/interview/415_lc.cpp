// Copyright (c) 2020 fxm.com, Inc. All Rights Reserved
// File Name: 415_lc.cpp
// Author: fangxiaoming01@baidu.com 
// Created Time: Wed 13 May 2020 10:29:39 AM CST

/**
 * 415. 字符串相加
 */

#include <iostream>
using namespace std;

int main() {
    std::string a = "123456789";
    //std::string b = "987654321123456";
    std::string b = "987654321";
    std::string sum = "";

    int carry = 0; // 进位标识

    // 从末尾开始相加
    for (int i = a.size()-1, j = b.size()-1; i>=0||j>=0; i--,j--) {

        int temp = carry; // 进位 
        temp += (i>=0) ? a[i] - '0' : 0; // 没有的补0对齐
        temp += (j>=0) ? b[j] - '0' : 0; // 同理
        
        // 进位 + a + b 各位相加，确定余数和进位
        
        sum.insert(sum.begin(), '0' + temp % 10);
        

        cout << sum << endl;

        carry = temp / 10; 
    }

    if (carry == 1) {
        sum.insert(sum.begin(), '1');
    }

    cout << sum << endl;

    return 0;
}
