// Copyright (c) 2020 fxm.com, Inc. All Rights Reserved
// File Name: 46_lc.cpp
// Author: fangxiaoming01@baidu.com 
// Created Time: Sun 17 May 2020 11:20:37 PM CST

#include <iostream>
using namespace std;

class Solution {
public:

    /*
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ret;
        vector<int> temp = nums;
        do {
            ret.push_back(temp);
            next_permutation(temp.begin(),temp.end());
        } while (temp != nums);

        return ret;
    }
    */


    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ret;
        vector<int> re;
        vector<int> used(nums.size(), 0);
        dfs(ret, re, used, nums);

        return ret;
    }

    void dfs(vector<vector<int>>& res, vector<int>& re, vector<int>& used, vector<int>& nums) {
        if (re.size() == nums.size()) {
            res.push_back(re);
            return;
        }

        for(int i = 0; i < nums.size(); ++i) {
            if (used[i] != 0) {
                continue;
            } else {
                re.push_back(nums[i]);
                used[i] = 1;

                dfs(res, re, used, nums);

                re.pop_back();
                used[i] = 0;
            }
        }
    }

};
