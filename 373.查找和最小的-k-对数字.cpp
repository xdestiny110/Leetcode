/*
 * @lc app=leetcode.cn id=373 lang=cpp
 *
 * [373] 查找和最小的 K 对数字
 */

// @lc code=start

#include <vector>
#include <queue>
#include <map>

class Solution {
public:
    std::vector<std::vector<int>> kSmallestPairs(std::vector<int>& nums1, std::vector<int>& nums2, int k) {
        // key: 乘积; val: 数组序号
        std::map<int, std::queue<std::vector<int>>> m;
        for (int i = 0; i < nums2.size(); ++i) {
            m[nums1[0] + nums2[i]].push({0, i});
        }

        std::vector<std::vector<int>> result;
        for (int i = 0; i < k; ++i) {
            if (m.empty()) break;
            auto k = m.begin()->first;
            auto& v = m.begin()->second;
            auto idx1 = v.front()[0];
            auto idx2 = v.front()[1];
            result.push_back({nums1[idx1], nums2[idx2]});
            v.pop();
            if (v.empty()) {
                m.erase(k);
            }
            if (idx1 < nums1.size() - 1)
                m[nums1[idx1 + 1] + nums2[idx2]].push({idx1 + 1, idx2});
        }
        return result;
    }
};
// @lc code=end

