// Copyright (c) 2020 fxm.com, Inc. All Rights Reserved
// File Name: 509_lc.cpp
// Author: fangxiaoming01@baidu.com 
// Created Time: Wed 13 May 2020 11:54:15 AM CST

#include <iostream>
#include <vector>
using namespace std;

/**
 *  509. 쳲������� 
 */

// T: O(2^n)
int fib(int n) {
    if (n == 1 || n == 2) {
        return n;
    }

    return fib(n-1) + fib(n-2);

}


int helper(vector<int>& memo, int n) {
    if (n==1 || n==2) return n;

    if (memo[n] != 0) {
        return memo[n];
    }

    memo[n] = helper(memo, n-1) + helper(memo, n-2);

    return memo[n];

}

// ���仯����, �ݹ�(�Զ�����, ���׺���㷵��)��T: O(n)�� �Զ�����
int fib1(int n) {
    if (n < 1) return 0;

    vector<int> memo(n+1, 0);
    
    return helper(memo, n);
}

// ��̬�滮(�Ե�����),����ʵ�� ������⣬ 
int fib2(int n) {
    vector<int> dp(n+1, 0); // ��ʼ��

    // base case
    dp[1] = dp[2] = 1;

    for (int i = 3; i <= n; ++i) {
        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[n];
}

// �ռ临�Ӷȣ���Ϊ O(1)
int fib3(int n) {
    if (n==1 || n==2) {
        return n;
    }
    int prev = 1;
    int curr = 1;
    for (int i = 3; i<=n; ++i) {
        int sum = prev + curr;
        prev = curr;
        curr = sum;
    }

    return curr;
}


int main() {

    return 0;
}
