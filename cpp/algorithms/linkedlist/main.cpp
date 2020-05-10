// Copyright (c) 2020 Baidu.com, Inc. All Rights Reserved
// File Name: main.cpp
// Author: fangxiaoming01@baidu.com 
// Created Time: Sun 10 May 2020 08:16:52 PM CST

#include <iostream>
#include "single_linked.h"
using namespace std;

int main(int argc, char* argv[]) {
    LinkedList my_link;
 
    my_link.add_at_head(5);
    my_link.add_at_head(3);
    my_link.add_at_head(8);

    cout << my_link.size << endl; 
    my_link.print();

    my_link.add_at_tail(10);
    my_link.add_at_tail(12);
    cout << my_link.size << endl;
    my_link.print();

    my_link.add_by_index(0, 101);
    my_link.print();

    my_link.add_by_index(my_link.size, 102);
    my_link.print();

    my_link.add_by_index(3, 103);
    my_link.print();

    cout << my_link.get_by_index(3) << endl;

    my_link.delete_by_index(3);
    my_link.print();



    return 0;
}
