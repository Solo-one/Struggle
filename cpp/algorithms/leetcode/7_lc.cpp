// Copyright (c) 2020 fxm.com, Inc. All Rights Reserved
// File Name: 7_lc.cpp
// Author: fangxiaoming01@baidu.com 
// Created Time: Sat 16 May 2020 06:25:17 PM CST

#include <iostream>
#include <string>
#include <limits.h>
using namespace std;

int func1() {
    //int x = 123;
    int x = -123;

    std::string ss = to_string(x);
    int start = 0;
    int end = ss.length() - 1;


    if (x < 0) {
        start = 1;
    }
 
    while (start < end) {
        char temp = ss[start];
        ss[start] = ss[end];
        ss[end] = temp;

        start++;
        end--;
    }


    cout << ss << endl;

    int ret = stoi(ss);
    int ret1 = atoi(ss.c_str());
    
    cout << ret << endl;

    return ret;
}

// 数学方法
int func2(int x) {
    int res = 0;
    while(x!=0) {
       if (res > INT_MAX/10) return 0;
       if (res < INT_MIN/10) return 0;

       res = res * 10;
       res = res + x % 10;
       x = x / 10;
    }

    return res;
}

// 7. 整数反转
int main() {
    cout << func2(-123) << endl; 
    return 0;
}
