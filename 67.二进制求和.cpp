/*
 * @lc app=leetcode.cn id=67 lang=cpp
 *
 * [67] 二进制求和
 */

#include <string>
#include <algorithm>

class Solution {
public:
    std::string addBinary(std::string a, std::string b) {
        if(a.size() > b.size())
            std::swap(a, b);
        std::reverse(a.begin(), a.end());
        std::reverse(b.begin(), b.end());
        std::string result;

        unsigned char isPlus = 0;
        for(int i = 0; i < a.size(); i++){
            auto c = a[i]-'0'+b[i]-'0'+isPlus;
            isPlus = 0;
            if(c > 1){
                isPlus = 1;
                c %= 2;
            }
            result.insert(result.cbegin(), c+'0');
        }

        for(int i = a.size(); i < b.size(); i++){
            auto c = b[i]-'0'+isPlus;
            isPlus = 0;
            if(c > 1){
                isPlus = 1;
                c %= 2;
            }
            result.insert(result.cbegin(), c+'0');
        }

        if(isPlus > 0)
            result.insert(result.cbegin(), '1');
        return result;
    }
};

