/*
 * @lc app=leetcode.cn id=2007 lang=cpp
 *
 * [2007] 从双倍数组中还原原数组
 */

// @lc code=start

#include <algorithm>
#include <vector>

class Solution {
public:
    std::vector<int> findOriginalArray(std::vector<int>& changed) {
        if (changed.size() % 2 != 0) return {};
        std::sort(changed.begin(), changed.end());
        std::vector<bool> visited(changed.size(), false);
        std::vector<int> result;
        result.reserve(changed.size() / 2);
        for (size_t i = 0; i < changed.size(); ++i) {
            if (!visited[i]) {
               auto it = std::lower_bound(changed.begin() + i + 1, changed.end(), changed[i] * 2);
                while (visited[std::distance(changed.begin(), it)] && it != changed.end() && *it == changed[i] * 2) {
                    ++it;
                }
                if (it != changed.end() && *it == changed[i] * 2) {
                    visited[std::distance(changed.begin(), it)] = true;
                } else {
                    return {};
                }
                result.push_back(changed[i]);
            }
        }
        return result;
    }
};
// @lc code=end

