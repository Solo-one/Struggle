// Copyright (c) 2020 fxm.com, Inc. All Rights Reserved
// File Name: 14_lc.cpp
// Author: fangxiaoming01@baidu.com 
// Created Time: Sat 16 May 2020 09:13:18 PM CST

#include <iostream>
#include <string>
#include <vector>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    int pre = 0;
    std::string first = strs[0];

    return first.substr(0, pre);
}

int main() {
    vector<string> ss;
    ss.push_back("aca");
    ss.push_back("cba");

    longestCommonPrefix(ss);

    return 0;
}
