// Copyright (c) 2020 fxm.com, Inc. All Rights Reserved
// File Name: 5_lc.cpp
// Author: fangxiaoming01@baidu.com 
// Created Time: Sat 16 May 2020 05:01:37 PM CST

#include <iostream>
using namespace std;

/**
 * 5. 最长回文子串
 */

int expendaroundcenter(std::string ss, int left, int right) {
    int L = left;
    int R = right;
    while (L>=0 && R<ss.length() && ss[L] == ss[R]) {
        L--; // 向左边扩展
        R++; // 向右边扩展
    }

    return R-L+1; // 扩展完后总的长度
}


std::string longestPalindrome(std::string ss) {
    if (ss.length() == 0) return "";
    

    int start, end;
    int len;

    for (int i=0; i<ss.length(); ++i) {
        int len1 = expendaroundcenter(ss, i, i); // 1个字符为中心点， n个
        int len2 = expendaroundcenter(ss, i, i+1); // 2个字符为中心点， n-1个
        len = std::max(std::max(len1, len2), len);
        
        // 找起始点
        if (len > (end - start)) {
            start = i - (len-1)/2;
            end = i + len/2;
        }
    }
   
    return ss.substr(start, len); // 截取回文串
}

int main() {

    return 0;
}
