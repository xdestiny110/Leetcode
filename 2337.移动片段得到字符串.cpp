/*
 * @lc app=leetcode.cn id=2337 lang=cpp
 *
 * [2337] 移动片段得到字符串
 */

// @lc code=start

#include <string>
#include <vector>

class Solution {
public:
    bool canChange(std::string start, std::string target) {
        auto start_lr_idx = generate_idx(start);
        auto target_lr_idx = generate_idx(target);
        if (start_lr_idx.size() != target_lr_idx.size())
            return false;
        
        for (size_t i = 0; i < start_lr_idx.size(); ++i) {
            const auto& [start_ch, start_idx] = start_lr_idx[i];
            const auto& [target_ch, target_idx] = target_lr_idx[i];
            if (start_ch != target_ch) 
                return false;
            if ((start_ch == 'L' && start_idx < target_idx) ||
                (start_ch == 'R' && start_idx > target_idx))
                return false;
        }
        return true;
    }

private:
    std::vector<std::pair<char, size_t>> generate_idx(const std::string& str) const {
        std::vector<std::pair<char, size_t>> lr_idx;
        for (size_t i = 0; i < str.size(); ++i) {
            if (str[i] == '_') continue;
            lr_idx.emplace_back(str[i], i);
        }
        return lr_idx;
    }
};
// @lc code=end

