// Copyright (c) 2020 fxm.com, Inc. All Rights Reserved
// File Name: thread_safe_queue.cpp
// Author: fangxiaoming01@baidu.com 
// Created Time: Sat 30 May 2020 12:22:39 PM CST

#include <iostream>
#include <queue>
#include <pthread.h>
using namespace std;

template <class T>
class ThreadSafeQueue {
public:
    ThreadSafeQueue() {
        pthread_mutex_init(&_mutex, NULL);
        pthread_cond_init(&_cond, NULL);
        Stopped = false;
    }

    void push(T data) {
        pthread_mutex_lock(&_mutex);
        m_queue.push(data);
        pthread_cond_signal(&_cond); // 等待过程分解为为：解锁--条件满足--加锁
        pthread_mutex_unlock(&_mutex);
    }

    T pop() {
        pthread_mutex_lock(&_mutex);
        if (m_queue.empty()) { // 队列空的时候需要等待
            pthread_cond_wait(&_cond, &_mutex);
        }

        /*
        while (m_queue.empty() && !Stopped) {
            pthread_cond_wait(&_cond, &_mutex);
        }
        */

        if (Stopped) {
            pthread_mutex_unlock(&_mutex);
            return NULL;
        }
        
        T t = m_queue.front();
        m_queue.pop();

        pthread_mutex_unlock(&_mutex);

        return t;
    }

    void stop() {
        pthread_mutex_lock(&_mutex);
        Stopped = true;
        pthread_cond_broadcast(&_cond); // 广播信号
        pthread_mutex_unlock(&_mutex);
    }

private:
    std::queue<T> m_queue;
    pthread_mutex_t _mutex;
    pthread_cond_t _cond;

    bool volatile Stopped;

};

int main() {

    return 0;
}
