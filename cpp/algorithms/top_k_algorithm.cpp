// Copyright (c) 2020 Baidu.com, Inc. All Rights Reserved
// File Name: top_k_algorithm.cpp
// Author: fangxiaoming01@baidu.com 
// Created Time: Mon 11 May 2020 01:49:36 PM CST

#include <iostream>
#include <vector>
using namespace std;

// 小顶堆
class MinHeap {
public:
    MinHeap(int k) {
        heap_size = k;
    }

    void create_min_heap(int arr[]) {
        for (int i = 0; i < heap_size; ++i) {
            vec.push_back(arr[i]);
        }

        // 小顶堆
        for (int i = vec.size()/2 -1; i >= 0; i--) { // 循环次数是，深度
            filetr_down(i);
        }
    }

    void insert(int val) {
        if (val > get_top()) {
            vec[0] = val;
            filetr_down(0);
        }
    }

    int get_top() {
        if (vec.size() != 0) {
            return vec[0];
        }

        return -1;
    }

    vector<int>& get_all_heap() {
        return vec;
    }

    // 核心
    void filetr_down(int current) {
        int end = vec.size() - 1;
        int child = current * 2 + 1;//当前节点的左孩子
        int val = vec[current]; //保存当前节点
        while (child <= end) {
            if (child < end && vec[child+1] < vec[child]) {
                child++;
            }
            if (val < vec[child]) {
                break;
            } else {
                vec[current] = vec[child];
                current = child;
                child = child * 2 + 1;
            }

        }
        vec[current] = val;
    }

private:
    int heap_size;
    vector<int> vec;
};

int main() {
    int arr[] = {1,7,6,4,2,9,8,3,5,0};
    int length = sizeof(arr) / sizeof(int);

    int top_k = 4;
    MinHeap heap(top_k);
    heap.create_min_heap(arr);

    // 从top_k开始遍历, 遍历完成，top_K即可求出
    for (int i = top_k; i < length; ++i) {
        heap.insert(arr[i]);
    }

    vector<int>& v = heap.get_all_heap();
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << endl;
    }

    return 0;
}
