/*
 * @lc app=leetcode.cn id=1441 lang=cpp
 *
 * [1441] 用栈操作构建数组
 */

// @lc code=start

#include <vector>
#include <string>
#include <optional>

class Solution {
public:
    std::vector<std::string> buildArray(std::vector<int>& target, int n) {
        std::vector<std::string> result;
        int last_num = 0;
        for (auto num : target) {
            result.insert(result.end(), num - last_num - 1, "Push");
            result.insert(result.end(), num - last_num - 1, "Pop");
            result.push_back("Push");
            last_num = num;
        }
        return result;
    }
};
// @lc code=end

