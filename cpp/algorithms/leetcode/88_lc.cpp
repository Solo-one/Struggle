// Copyright (c) 2020 fxm.com, Inc. All Rights Reserved
// File Name: 88_lc.cpp
// Author: fangxiaoming01@baidu.com 
// Created Time: Sat 16 May 2020 11:40:44 PM CST

#include <iostream>
using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    vector<int> result;
    int i=0,j=0,k=0;
    while (i<m && j <n) {
        if (nums1[i] < nums2[j]) {
            result[k++] = nums1[i++];
        } else {
            result[k++] = nums2[j++];
        }
    }

    while (i < m) {
        result[k++] = nums1[i++];
    }

    while (j < n) {
        result[k++] = nums2[j++];
    }

    nums1.clear();
    nums1.insert(nums1.end(), result.begin(), result.end());
}

int main() {

    return 0;
}
