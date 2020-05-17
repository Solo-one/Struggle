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

        pair<int, int> kv = *map[key]; // key 存在，把 (k, v) 换到队头
        cache.erase(map[key]); // 删除
        cache.push_front(kv);

        map[key] = cache.begin();
        return kv.second;
    }

    void put(int key, int value) {
        // 要先判断 key 是否已经存在
        auto it = map.find(key);
        if (it == map.end()) {
            //key 不存在，判断 cache 是否已满
            if (cache.size() == _cap) {
                auto lastPair = cache.back();
                int lastKey = lastPair.first;
                map.erase(lastKey); // cache 已满，删除尾部的键值对腾位置
                cache.pop_back(); // cache 和 map 中的数据都要删除


                cache.push_front(make_pair(key, value));
                map[key] = cache.begin();
            } else {
                cache.push_front(make_pair(key, value));
                map[key] = cache.begin();
            }


        } else {
            // key 存在，更改 value 并换到队头 
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
