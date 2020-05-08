// Copyright (c) 2020 Baidu.com, Inc. All Rights Reserved
// File Name: demo_0_0.c
// Author: fangxiaoming01@baidu.com 
// Created Time: Thu 07 May 2020 10:39:34 AM CST

#include <stdio.h>

union test {
    short val;
    char array[2];
};

int check_sys() {
    int i = 1;
    //return (char)i;
    return *(char*)&i;
}

/**
 *  测试本机大小端序
 *  1、使用联合体 2、
 */
int main(int argc, char* argv[]) {
    union test t;
    t.val = 0x0102; // 从左到右，左边高字节，右边低字节
    printf("low[%p] high[%p]\n", &t.array[0], &t.array[1]);

    if (t.array[0] == 1 && t.array[1] == 2) {
        printf("big endian.\n");
    } else if (t.array[0] == 2 && t.array[1] == 1) {
        printf("small endian.\n");
    } else {
        printf("error.\n");
    }

    //
    if (check_sys() == 0) {
        printf("big endian.\n");
    } else if (check_sys() == 1){
        printf("small endian.\n");
    }

    return 0;
}

/**
 *  总结：
 *  1、大端字节序：高字节存放低地址，低字节存放高地址
 *  2、小端字节序：高字节存放高地址，低字节存放低地址
 *
 */
