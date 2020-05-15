// Copyright (c) 2020 fxm.com, Inc. All Rights Reserved
// File Name: binary_search.cpp
// Author: fangxiaoming01@baidu.com 
// Created Time: Fri 15 May 2020 09:27:13 PM CST

#include <iostream>
#include <cmath>
using namespace std;

// 已按绝对值排好序的数组，给定一个数，找出该数下标，若没有找到则返回-1
int binary_search(int array[], int length, int start, int end, int search) {
    int mid = (end - start) / 2 + start;
    if (start > end) {
        return -1;
    }

    if (abs(search) > abs(array[mid])) {
        return binary_search(array, length, mid + 1, end, search);
    } else if (abs(search) < abs(array[mid])) {
        return binary_search(array, length, start, mid - 1, search);
    } else {
        if (search == array[mid]) {
            return mid;
        }
        if (search == array[mid+1]) {
            return mid+1;
        }
        if (search == -array[mid-1]) {
            return mid-1;
        }
    }

    return -1;
}

int main() {
    //int array[] = {1, 3, 8, 10, 11, 12, 26, 40, 80, 100};
    int array[] = {1, -2, 3, -3, 5, 11, 26, -40, 100};
    int length = sizeof(array) / sizeof(*array);

    cout << binary_search(array, length, 0, length -1, 11) << endl;
    cout << binary_search(array, length, 0, length -1, -3) << endl;
    cout << binary_search(array, length, 0, length -1, -40) << endl;
    cout << binary_search(array, length, 0, length -1, -41) << endl;

    return 0;
}
