/*
 * @lc app=leetcode.cn id=2808 lang=cpp
 *
 * [2808] 使循环数组所有元素相等的最少秒数
 */

// @lc code=start
#include <vector>
#include <unordered_map>

class Solution {
public:
    int minimumSeconds(std::vector<int>& nums) {
        // 用hash表存储，每个数在数组中出现的位置
        int n = nums.size();
        std::unordered_map<int, std::vector<int>> umap;
        for (int i = 0; i < n; i++) {
            umap[nums[i]].push_back(i);
        }
        int ans = n;
        // 枚举每个数使数组所有元素相等的最少秒数
        for (auto &iter : umap) {
            auto &v = iter.second;
            v.push_back(v[0] + n);// 处理循环数组
            int mx = - 1;
            for (int i = 1; i < v.size(); i++) {
                mx = std::max(mx, (v[i] - v[i - 1]) / 2);
            }
            ans = std::min(ans, mx);
        }
        return ans;
    }
};
// @lc code=end

