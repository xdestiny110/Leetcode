/*
 * @lc app=leetcode.cn id=670 lang=cpp
 *
 * [670] 最大交换
 */

// @lc code=start
#include <string>
class Solution {
public:
    int maximumSwap(int num) {
        auto num_str = std::to_string(num);
        std::vector<std::pair<char, int>> max_str(num_str.size());
        max_str.back() = { num_str.back(), num_str.size() - 1 };
        for (int i = num_str.size() - 2; i >= 0; --i) {
            if (num_str[i] <= max_str[i + 1].first) {
                max_str[i] = max_str[i + 1];
            } else {
                max_str[i] = { num_str[i], i };
            }
        }
        
        for (int i = 0; i < num_str.size(); ++i) {
            if (num_str[i] != max_str[i].first) {
                std::swap(num_str[i], num_str[max_str[i].second]);
                break;
            }
        }
        return std::stod(num_str);
    }
};
// @lc code=end

