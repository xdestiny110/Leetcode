/*
 * @lc app=leetcode.cn id=414 lang=cpp
 *
 * [414] 第三大的数
 */

// @lc code=start
#include <vector>
#include <optional>

class Solution {
public:
    int thirdMax(std::vector<int>& nums) {
        std::optional<int> biggest = std::nullopt, bigger = std::nullopt, big = std::nullopt;
        for (auto num : nums) {
            if (!biggest.has_value() || num > *biggest) {
                std::swap(bigger, big);
                std::swap(biggest, bigger);
                biggest = num;
            } else if ((!bigger.has_value() || num > *bigger) && *biggest != num) {
                std::swap(bigger, big);
                bigger = num;
            } else if ((!big.has_value() || num > *big) && *biggest != num && *bigger != num) {
                big = num;
            }
        }
        return big.has_value() ? *big : *biggest;
    }
};
// @lc code=end

