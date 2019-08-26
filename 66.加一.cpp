/*
 * @lc app=leetcode.cn id=66 lang=cpp
 *
 * [66] 加一
 */

#include <vector>

class Solution {
public:
    std::vector<int> plusOne(std::vector<int>& digits) {
        bool isPlus = true;
        for(auto it = digits.rbegin(); it != digits.rend(); it++){
            if(isPlus){
                *it+=1;
                if(*it > 9)
                    *it = 0;
                else
                    isPlus = false;
            }
        }
        if(isPlus)
            digits.insert(digits.begin(), 1);
        return digits;
    }
};

