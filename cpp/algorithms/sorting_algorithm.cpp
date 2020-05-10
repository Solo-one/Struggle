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
 * ���ƣ�������
 * ƽ��ʱ�临�Ӷȣ�O(nlogn)
 * �ռ临�Ӷȣ�O(1)
 * Ӧ�ã����������˵��һ�����öѵĸ����������ѡ������
 * С���ѣ�ÿ���ڵ��ֵ��С�ڻ�������ӽڵ��ֵ���ڶ������㷨�����ڽ������У�
 * �󶥶ѣ�ÿ���ڵ��ֵ�����ڻ�������ӽڵ��ֵ���ڶ������㷨�������������У�
 */
void heap_sorting(int array[], int size) {
    //��(n/2-1) --> 0��α���������֮�󣬵õ�������ʵ������һ��(���)
    for (int i = (size/2 -1); i >= 0; --i) { // size_t ���ص��޷�����������
        heap_max_adjust(array, i, size-1);
        //heap_min_adjust(array, i, size-1);
    }

    //�����һ��Ԫ�ؿ�ʼ�����н��е��������ϵ���С�����ķ�Χֱ����һ��Ԫ��
    for (int i = size -1; i > 0; --i) {
        // ����a[0]��a[i]��������a[i]��a[0...i]�����ġ�
        int temp = array[0];
        array[0] = array[i];
        array[i] = temp;
        // ����a[0...i-1]��ʹ��a[0...i-1]��Ȼ��һ�����ѡ�������֤a[i-1]��a[0...i-1]�е����ֵ��
        heap_max_adjust(array, 0, i-1); // �Ӷ��㿪ʼ����, �������һ��
        //heap_min_adjust(array, 0, i-1);
    }
}

void heap_max_adjust(int array[], int start, int end) {
    int c = start;            // ��ǰ(current)�ڵ��λ��
    int l = 2 * start + 1;
    int temp = array[start];

    for (; l <= end; c=l,l=2*l+1) {
        if ( l < end && array[l] < array[l+1]) {
            l++;        // ������������ѡ��ϴ��ߣ���m_heap[l+1]
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
    int c = start;            // ��ǰ(current)�ڵ��λ��
    int l = 2 * start + 1; // ��(left)���ӵ�λ��
    int temp = array[start]; // ��ǰ(current)�ڵ�Ĵ�С

    for (; l <= end; c=l,l=2*l+1) {
        if (l < end && array[l] > array[l+1]) {
            l++;        // ������������ѡ��ϴ��ߣ���m_heap[l+1]
        }
        
        if (temp <= array[l]) {
            break;
        } else { // ����ֵ
            array[c] = array[l];
            array[l]= temp;
        }
    }
}


/**
 * ���ƣ���������
 * ƽ��ʱ�临�Ӷȣ�O(n^2)
 * �ռ临�Ӷȣ�O(1)
 * Ӧ�ã�Ч�ʱȽϵ�, ʱ�临�Ӷ�һֱ����O(n^2)
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
 * ���ƣ�ѡ������
 * ƽ��ʱ�临�Ӷȣ�O(n^2)
 * �ռ临�Ӷȣ�O(1)
 * Ӧ�ã�Ч�ʱȽϵ�, ʱ�临�Ӷ�һֱ����O(n^2)
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
 * ���ƣ��鲢����
 * ƽ��ʱ�临�Ӷȣ�O(nlogn)
 * �ռ临�Ӷȣ�O(n)
 * Ӧ�ã�����ʹ�÷��η�, ��Կ��ţ���Ҫ����ռ�
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
 * ���ƣ���������
 * ƽ��ʱ�临�Ӷȣ�O(nlogn)
 * �ռ临�Ӷȣ�O(logn)
 * Ӧ�ã���������ʹ�÷��η�,ʵ��Ӧ�ñȽ϶�
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

    // ������׼
    int temp = array[i+1];
    array[i+1] = array[high];
    array[high] = temp;

    return i + 1;
}


/**
 * ���ƣ�ð������
 * ƽ��ʱ�临�Ӷȣ�O(n^2)
 * �ռ临�Ӷȣ�O(1)
 * Ӧ�ã�Ч�ʲ��ߣ��ʺ�С��������
 */
void bubble_sorting(int array[], int size) {
    for (size_t i = 0; i < size; ++i) {
        for (size_t j = (i+1); j < size; ++j) {
            // ����
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

// ������ӡ
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
 * �ܽ᣺ѧϰ��ַ��https://mp.weixin.qq.com/s/08IBU82Nh4YdAGmkmyp00g
 * ���������㷨����д��
 */
