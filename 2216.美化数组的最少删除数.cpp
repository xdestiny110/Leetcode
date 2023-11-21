/*
 * @lc app=leetcode.cn id=2216 lang=cpp
 *
 * [2216] 美化数组的最少删除数
 */

// @lc code=start
#include <vector>

class Solution {
public:
    int minDeletion(std::vector<int>& nums) {
        if (nums.empty()) return 0;
        if (nums.size() == 1) {
            return 1;
        }

        int remove_cnt = 0;
        for (int i = 0, j = 1; i < nums.size() && j < nums.size();) {
            if (nums[i] == nums[j]) {
                remove_cnt++;
                j++;
            } else {
                i = j + 1;
                j = i + 1;
            }
        }
        return ((nums.size() - remove_cnt) % 2 == 0) ? remove_cnt : remove_cnt + 1;
    }
};
// @lc code=end

