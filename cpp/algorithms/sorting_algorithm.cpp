// Copyright (c) 2020 Baidu.com, Inc. All Rights Reserved
// File Name: sorting_algorithm.cpp
// Author: fangxiaoming01@baidu.com 
// Created Time: Fri 08 May 2020 08:27:37 PM CST

#include <iostream>
#include <string.h>
using namespace std;

void print_sort(int array[], int size);
int partition(int array[], int low, int high);
void merge(int array[], int* left, int left_size, int* right, int right_size);
void heap_max_adjust(int array[], int start, int end);
void heap_min_adjust(int array[], int start, int end);

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void swap(int array[], int a_idx, int b_idx) {
    int temp = array[a_idx];
    array[a_idx] = array[b_idx];
    array[b_idx] = temp;
}

/**
 * 名称：堆排序
 * 平均时间复杂度：O(nlogn)
 * 空间复杂度：O(1)
 * 应用：堆排序可以说是一种利用堆的概念来排序的选择排序
 * 小顶堆：每个节点的值都小于或等于其子节点的值，在堆排序算法中用于降序排列；
 * 大顶堆：每个节点的值都大于或等于其子节点的值，在堆排序算法中用于升序排列；
 */
void heap_sorting(int array[], int size) {
    //从(n/2-1) --> 0逐次遍历。遍历之后，得到的数组实际上是一个(最大)
    for (int i = (size/2 -1); i >= 0; --i) { // size_t 返回的无符号整数类型
        heap_max_adjust(array, i, size-1);
        //heap_min_adjust(array, i, size-1);
    }

    //从最后一个元素开始对序列进行调整，不断的缩小调整的范围直到第一个元素
    for (int i = size -1; i > 0; --i) {
        // 交换a[0]和a[i]。交换后，a[i]是a[0...i]中最大的。
        int temp = array[0];
        array[0] = array[i];
        array[i] = temp;
        // 调整a[0...i-1]，使得a[0...i-1]仍然是一个最大堆。即，保证a[i-1]是a[0...i-1]中的最大值。
        heap_max_adjust(array, 0, i-1); // 从顶点开始建堆, 忽略最后一个
        //heap_min_adjust(array, 0, i-1);
    }
}

void heap_max_adjust(int array[], int start, int end) {
    int c = start;            // 当前(current)节点的位置
    int l = 2 * start + 1;
    int temp = array[start];

    for (; l <= end; c=l,l=2*l+1) {
        if ( l < end && array[l] < array[l+1]) {
            l++;        // 左右两孩子中选择较大者，即m_heap[l+1]
        }
        
        if (temp >= array[l]) {
            break;
        } else {
            array[c] = array[l];
            array[l]= temp;
        }
    }
}

void heap_min_adjust(int array[], int start, int end) {
    int c = start;            // 当前(current)节点的位置
    int l = 2 * start + 1; // 左(left)孩子的位置
    int temp = array[start]; // 当前(current)节点的大小

    for (; l <= end; c=l,l=2*l+1) {
        if (l < end && array[l] > array[l+1]) {
            l++;        // 左右两孩子中选择较大者，即m_heap[l+1]
        }
        
        if (temp <= array[l]) {
            break;
        } else { // 交换值
            array[c] = array[l];
            array[l]= temp;
        }
    }
}


/**
 * 名称：插入排序
 * 平均时间复杂度：O(n^2)
 * 空间复杂度：O(1)
 * 应用：效率比较低, 时间复杂度一直都是O(n^2)
 */
void insert_sorting(int array[], int size) {
    for (size_t i = 0; i < size; ++i) {
        int pre_index = i - 1;
        int current = array[i];
        while (pre_index >= 0 && array[pre_index] > current) {
            array[pre_index+1] = array[pre_index];
            pre_index--;
        }
        array[pre_index+1] = current;
    }
}


/**
 * 名称：选择排序
 * 平均时间复杂度：O(n^2)
 * 空间复杂度：O(1)
 * 应用：效率比较低, 时间复杂度一直都是O(n^2)
 */
void select_sorting(int array[], int size) {
    for (size_t i = 0; i < size; ++i) {
        int min_index = i;
        for (size_t j = i+1; j < size; ++j) {
            if (array[j] < array[min_index]) {
                min_index = j;
            }
        }

        if (i != min_index) {
            int temp = array[i]; 
            array[i] = array[min_index];
            array[min_index] = temp;
        }
    }
}


/**
 * 名称：归并排序
 * 平均时间复杂度：O(nlogn)
 * 空间复杂度：O(n)
 * 应用：排序使用分治法, 相对快排，需要更多空间
 */
void merge_sorting(int array[], int size) {
    int mid, i;
    int *left, *right; 
    if (size < 2) {
        return;
    }

    mid = size / 2;
    left = new int[mid];
    right = new int[size - mid];

    for (size_t i = 0; i < mid; ++i) {
        left[i] = array[i];
    }
    for (size_t i = mid; i < size; ++i) {
        right[i-mid] = array[i];
    }

    merge_sorting(left, mid);
    merge_sorting(right, size - mid);

    merge(array, left, mid, right, size-mid);

    delete [] left;
    delete [] right;
}

void merge(int array[], int* left, int left_size, int* right, int right_size) {
    int i=0,j=0,k=0;
    while (i<left_size && j<right_size) {
        if (left[i] < right[j]) {
            array[k++] = left[i++];
        } else {
            array[k++] = right[j++];
        }
    }

    while (i<left_size) {
        array[k++] = left[i++];
    }
    while (j<right_size) {
        array[k++] = right[j++];
    }
}


/**
 * 名称：快速排序
 * 平均时间复杂度：O(nlogn)
 * 空间复杂度：O(logn)
 * 应用：快速排序使用分治法,实际应用比较多
 */
void quick_sorting(int array[], int low, int high) {
    if (low < high) {
        int mid = partition(array, low, high); 
        quick_sorting(array, low, mid - 1);
        quick_sorting(array, mid + 1, high);
    }
}

int partition(int array[], int low, int high) {
    int pivot = array[high];
    int i = low - 1;
    for (size_t j = low; j < high; ++j) {
        if (array[j] < pivot) {
            i++;

            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }

    }

    // 更换基准
    int temp = array[i+1];
    array[i+1] = array[high];
    array[high] = temp;

    return i + 1;
}


/**
 * 名称：冒泡排序
 * 平均时间复杂度：O(n^2)
 * 空间复杂度：O(1)
 * 应用：效率不高，适合小数据排序
 */
void bubble_sorting(int array[], int size) {
    for (size_t i = 0; i < size; ++i) {
        for (size_t j = (i+1); j < size; ++j) {
            // 交换
            /*
            if (array[i] > array[j]) {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
            */

            if (array[i] > array[j]) {
                swap(array[i], array[j]);
            }

        }
    }
}

// 遍历打印
void print_sort(int array[], int size) {
    for (size_t i = 0; i < size; ++i) {
        cout << array[i] << " ";
    }
    cout << endl;
}

// low -> high
int main() {
    int array[] = {1, 20, 9, 13, 50, 3, 100, 6, 101, 55};
    int length = sizeof(array)/sizeof(array[0]);
    cout << "array length:" << length << endl;
    cout << "before sort:" << endl;
    print_sort(array, length);

    //bubble_sorting(array, length);
    //cout << "after bubble_sorting:" << endl;
    //print_sort(array, length);

    //quick_sorting(array, 0, length - 1);
    //cout << "after quick_sorting:" << endl;
    //print_sort(array, length);

    //merge_sorting(array, length);
    //cout << "after merge_sorting:" << endl;
    //print_sort(array, length);

    //select_sorting(array, length);
    //cout << "after select_sorting:" << endl;
    //print_sort(array, length);

    //insert_sorting(array, length);
    //cout << "after insert_sorting:" << endl;
    //print_sort(array, length);

    heap_sorting(array, length);
    cout << "after heap_sorting:" << endl;
    print_sort(array, length);

    return 0;
}

/**
 * 总结：学习地址：https://mp.weixin.qq.com/s/08IBU82Nh4YdAGmkmyp00g
 * 熟练排序算法，手写。
 */
