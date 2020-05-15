// Copyright (c) 2020 fxm.com, Inc. All Rights Reserved
// File Name: main.cpp
// Author: fangxiaoming01@baidu.com 
// Created Time: Fri 15 May 2020 11:29:55 AM CST

#include <iostream>
#include <stdlib.h>
using namespace std;


int main() {
    
    int* array = (int*) malloc(sizeof(int));

    free(array);
    //free(array);

    return 0;
}

/**
 * https://murphypei.github.io/blog/2019/04/valgrind-memory-leaky
 * 
 */
