/*
 * @lc app=leetcode.cn id=1103 lang=cpp
 *
 * [1103] 分糖果 II
 */

// @lc code=start
#include <vector>

class Solution {
public:
    std::vector<int> distributeCandies(int candies, int num_people) {
        std::vector<int> result(num_people);
        for (size_t idx = 0, current_candies = 1; ; current_candies++) {
            if (current_candies >= candies) {
                result[idx] += candies;
                break;
            }
            result[idx] += current_candies;
            candies -= current_candies;
            idx = (idx + 1) % num_people;
        }
        return result;
    }
};
// @lc code=end

