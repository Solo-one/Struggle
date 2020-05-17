// Copyright (c) 2020 fxm.com, Inc. All Rights Reserved
// File Name: 146_lc_lru.cpp
// Author: fangxiaoming01@baidu.com 
// Created Time: Sun 17 May 2020 07:59:12 PM CST

#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;

class LRUCache {
public:
    LRUCache(int capacity) {
        _cap = capacity;
    }

    int get(int key) {
        auto it = map.find(key);
        if (it == map.end()) {
            return -1;
        }

        pair<int, int> kv = *map[key]; // key ���ڣ��� (k, v) ������ͷ
        cache.erase(map[key]); // ɾ��
        cache.push_front(kv);

        map[key] = cache.begin();
        return kv.second;
    }

    void put(int key, int value) {
        // Ҫ���ж� key �Ƿ��Ѿ�����
        auto it = map.find(key);
        if (it == map.end()) {
            //key �����ڣ��ж� cache �Ƿ�����
            if (cache.size() == _cap) {
                auto lastPair = cache.back();
                int lastKey = lastPair.first;
                map.erase(lastKey); // cache ������ɾ��β���ļ�ֵ����λ��
                cache.pop_back(); // cache �� map �е����ݶ�Ҫɾ��


                cache.push_front(make_pair(key, value));
                map[key] = cache.begin();
            } else {
                cache.push_front(make_pair(key, value));
                map[key] = cache.begin();
            }


        } else {
            // key ���ڣ����� value ��������ͷ 
            cache.erase(map[key]);
            cache.push_front(make_pair(key, value));
            map[key] = cache.begin();
        }
    }

private:
    int _cap;
    std::list<pair<int, int>> cache;
    unordered_map<int, std::list<pair<int, int>>::iterator> map; 
};

int main () {

    return 0;
}
