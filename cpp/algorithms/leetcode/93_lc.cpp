// Copyright (c) 2020 fxm.com, Inc. All Rights Reserved
// File Name: 93_lc.cpp
// Author: fangxiaoming01@baidu.com 
// Created Time: Mon 11 May 2020 04:03:50 PM CST

#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    vector<string> ans;//存放最终的结果

    void findIpAddress(const string& s, int pos, vector<string>& path){
        int maxSize = (4-path.size())*3;//剩余位数的最大长度，最大为12
        if(s.size()-pos>maxSize) return; // 若剩余位数大于最大剩余位数长度，可提前终止
        if(path.size()==4 && pos == s.size()){
            string str = path[0]+"."+path[1]+"."+path[2]+"."+path[3];
            ans.push_back(str);//存放结果
            return;
        }

        //递归回溯
        //i<字符串s的长度，并且ip字串的长度不会超过3
        for(int i=pos;i<s.size()&&i<=pos+2;++i){
            string ip = s.substr(pos,i-pos+1);
            if(isValid(ip)){
                path.push_back(ip);
                findIpAddress(s,i+1,path);
                path.pop_back();//手动对path进行回溯
            }
        }
    }

    bool isValid(string ip){
        int val = stoi(ip);
        if (val>255) return false;

        if (ip.size()>=2 && ip[0] == '0') {
            return false; //当ip子串长度大于2时,开头不能为0
        }

        return true;
    }

public:
    vector<string> restoreIpAddresses(string s) {
        if(s.size()<4) return ans;
        vector<string> path;

        findIpAddress(s,0,path);
        return ans;
    }

};

int main() {

    Solution s;
    vector<string> ss = s.restoreIpAddresses("25525511135");

    for (int i = 0; i<ss.size(); ++i) {
        cout << ss[i] << endl;
    }   


    return 0;
}
