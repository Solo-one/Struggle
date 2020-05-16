// Copyright (c) 2020 fxm.com, Inc. All Rights Reserved
// File Name: 53_lc.cpp
// Author: fangxiaoming01@baidu.com 
// Created Time: Sat 16 May 2020 11:00:09 PM CST

#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

// 53.最大子序和

// 动态规划
int maxSubArray(vector<int> &nums) {
    
    int result = INT_MIN;

    int size = nums.size();

    int dp = nums[0];

    result = dp;

    for (int i = 0; i < size; ++i) {
        dp = max(dp+nums[i], nums[i]);
        result = max(result, dp);
    }

    return result;
}

// 贪心算法
int maxSubArray1(vector<int> &nums) {

    int result = INT_MIN;
    int size = nums.size();
    int sum = 0;

    for (int i = 0; i < size; ++i) {
        sum += nums[i];
        result = max(result, sum);
        if (sum < 0) {
            sum = 0;
        }
    }

    return result;
}

int main() {

    return 0;
}

