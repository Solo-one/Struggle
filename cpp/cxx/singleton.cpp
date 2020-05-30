// Copyright (c) 2020 fxm.com, Inc. All Rights Reserved
// File Name: singleton.cpp
// Author: fangxiaoming01@baidu.com 
// Created Time: Thu 28 May 2020 02:00:48 PM CST

#include <iostream>
#include <mutex>
#include <pthread.h>
using namespace std;


// 饿汉单列模式，本身线程安全
class Singleton_e {
public:
    static Singleton_e* get_instance() {
        return instance;
    }

    static Singleton_e* get_instance1() {
        return &e_instance;
    }

private:
    static Singleton_e* instance;
    static Singleton_e e_instance; // 静态变量
    Singleton_e() {}
    ~Singleton_e() {}

    Singleton_e(const Singleton_e&) {}
    Singleton_e& operator=(const Singleton_e&) {}
};

Singleton_e* Singleton_e::instance = new (std::nothrow) Singleton_e();


// 线程安全，懒汉单列模式
class Singleton {
public:
    static Singleton* get_instance() {
        if (m_instance == NULL) {
            pthread_mutex_lock(&_mutex);
            if (m_instance == NULL) {
                m_instance = new (std::nothrow) Singleton();
            }
            pthread_mutex_unlock(&_mutex);
        }
        return m_instance;
    }

private:
    static Singleton* m_instance;
    static pthread_mutex_t _mutex;

private:
    Singleton() {
        pthread_mutex_init(&_mutex, NULL);
    }
    ~Singleton() {}

    Singleton(const Singleton&) {};
    Singleton& operator=(const Singleton&) {};

};

int main() {
    std::string a = "a";

    a.insert(a.begin(), 'b');
    cout << a << endl;

    a.insert(0, "dc");
    cout << a << endl;

    return 0;
}
