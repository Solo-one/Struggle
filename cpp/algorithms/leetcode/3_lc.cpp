// Copyright (c) 2020 Baidu.com, Inc. All Rights Reserved
// File Name: 3_lc.cpp
// Author: fangxiaoming01@baidu.com 
// Created Time: Mon 11 May 2020 03:00:02 PM CST

#include <iostream>
using namespace std;

int lengthOfLongestSubstring(std::string s) {
    int start = 0, end = 0;
    int length = 0;
    int ret = 0;

    while (end < s.size()) {
        char temp_char = s[end];

        for (int index = start; index < end; ++index) {
            if (temp_char == s[index]) {
                start = index + 1;
                length = end - start;

                break;
            }
        }
        end++;
        length++;
        ret = max(ret, length);
    }

    return ret;
}

int main() {
    std::string s = "abcabcbb";
    int length = lengthOfLongestSubstring(s);
    cout << length << endl;
    
    s = "bbbbb";
    cout << lengthOfLongestSubstring(s) << endl;

    s = "pwwkew";
    cout << lengthOfLongestSubstring(s) << endl;

    return 0;
}
