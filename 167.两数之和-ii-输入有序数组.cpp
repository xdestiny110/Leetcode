/*
 * @lc app=leetcode.cn id=167 lang=cpp
 *
 * [167] 两数之和 II - 输入有序数组
 */

// @lc code=start

#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& numbers, int target) {
        std::unordered_map<int, int> s;
        s.reserve(numbers.size());
        for(int i = 0; i < numbers.size(); ++i){
            auto it = s.find(target - numbers[i]);
            if(it != s.end()){
                return {it->second + 1, i + 1};
            }
            s[numbers[i]] = i;
        }
        return {0,0};
    }
};
// @lc code=end

