// Copyright (c) 2020 fxm.com, Inc. All Rights Reserved
// File Name: 43_lc.cpp
// Author: fangxiaoming01@baidu.com 
// Created Time: Mon 18 May 2020 11:13:27 AM CST

#include <iostream>
using namespace std;

// 43. 字符串相乘
class Solution {
    public:
        string multiply(string num1, string num2) {
            int len1 = num1.length();
            int len2 = num2.length();
            vector<int> v(len1 + len2, 0);

            for (int i = len1 - 1; i >= 0; i--) {
                for (int j = len2 - 1; j >= 0; j--) {
                    // 此处很巧妙，对应位乘完后相加，并始终不进位
                    v[i+j+1] += (num1[i] - '0') * (num2[j] - '0'); 
                }
            }

            int carry = 0;
            for (int i = len1 + len2 - 1; i >= 0; i--) {
                v[i] += carry;
                carry = v[i] / 10;
                v[i] = v[i] % 10;
            }

            string re = "";
            int flag = 1;
            for (int i = 0; i < len1 + len2; ++i) {
                if (v[i] == 0 && flag)continue;
                re += v[i] + '0';
                flag = 0;
            }
            if (flag) {
                re += '0';
            }

            return re;
        }
};
