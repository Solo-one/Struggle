// Copyright (c) 2020 fxm.com, Inc. All Rights Reserved
// File Name: strcpy.cpp
// Author: fangxiaoming01@baidu.com 
// Created Time: Sun 31 May 2020 09:26:54 AM CST

#include <iostream>
#include <assert.h>
#include <stdio.h>
using namespace std;

char* strcpy(char* dest, const char* src) {
    
    assert(dest != NULL); // true, ¼ÌÐøÖ´ÐÐ; false, stderr, abortÍË³ö
    assert(src != NULL);
    
    char* ret = dest;
    while (*src != '\0') {
        *dest = *src;
        src++;
        dest++;
    }

    return ret;
}

int main() {
    char *a = "hello";

    //char* b = new char[10];
    char b[3];
    strcpy(b, a);

    cout << b << endl;

    return 0;
}
