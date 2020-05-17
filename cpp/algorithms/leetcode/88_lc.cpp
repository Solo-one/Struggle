// Copyright (c) 2020 fxm.com, Inc. All Rights Reserved
// File Name: 88_lc.cpp
// Author: fangxiaoming01@baidu.com 
// Created Time: Sat 16 May 2020 11:40:44 PM CST

#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    vector<int> result;
    int i=0,j=0,k=0;
    while (i<m && j <n) {
        if (nums1[i] < nums2[j]) {
            result.push_back(nums1[i++]);
        } else {
            result.push_back(nums2[j++]);
        }
    }

    while (i < m) {
        result.push_back(nums1[i++]);
    }

    while (j < n) {
        result.push_back(nums2[j++]);
    }

    nums1.clear();
    nums1.insert(nums1.end(), result.begin(), result.end());
}

int main() {

    vector<int> nums1;
    nums1.push_back(1);
    nums1.push_back(2);
    nums1.push_back(3);
    nums1.push_back(0);

    vector<int> nums2;
    nums2.push_back(2);
    nums2.push_back(5);
    nums2.push_back(6);

    merge(nums1, 3, nums2, 3);

    return 0;
}
