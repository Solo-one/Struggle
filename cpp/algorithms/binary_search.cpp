// Copyright (c) 2020 Baidu.com, Inc. All Rights Reserved
// File Name: demo_01.cpp
// Author: fangxiaoming01@baidu.com 
// Created Time: Wed 06 May 2020 11:29:36 PM CST

#include <iostream>
using namespace std;

/**
 * 递归二分查找
 */
int binary_search(int array[], int length, int start, int end, int search) {
    int mid = (end - start) / 2 + start;
    //cout << mid << endl;
   
    if (start > end) {
        return -1;
    }

    if (search > array[mid]) {
        return binary_search(array, length, mid + 1, end, search);
    } else if (search < array[mid]) {
        return binary_search(array, length, start, mid - 1, search);
    } else {
        return mid;
    }

    return -1;    
}

/**
 * 普通二分查找
 */
int binary_search(int array[], int length, int search) {
    int start = 0;
    int end = length - 1;
    for (size_t i = 0; i < length; ++i) {
        int mid = (end - start) / 2 + start; 
        if (search < array[mid]) {
            end = mid - 1;   
        } else if (search > array[mid]) {
            start = mid + 1;
        } else {
            return mid;
        }
    }

    return -1;
}

int main(int argc, char* argv[]) {
    int array[] = {1, 3, 8, 10, 11, 12, 26, 40, 80, 100};
    int length = sizeof(array) / sizeof(*array);
    cout << length << endl;

    cout << binary_search(array, length, 0, length -1, 11) << endl;
    cout << binary_search(array, length, 11) << endl;

    return 0;
}
