// Copyright (c) 2020 fxm.com, Inc. All Rights Reserved
// File Name: demo_01.cpp
// Author: fangxiaoming01@baidu.com 
// Created Time: Wed 10 Jun 2020 10:55:14 AM CST

#include <iostream>
#include <stdio.h>
using namespace std;


int main() {
    uint64_t ab = 20;
    uint64_t a = 12034660004;

    char* bid = (char*)&a;
    printf("%s\n", bid);

    uint64_t *ss = (uint64_t*) bid;
    uint64_t aaa = *ss;
    printf("%lu", aaa);



    return 0;
}
