/*
 * @lc app=leetcode.cn id=2592 lang=cpp
 *
 * [2592] 最大化数组的伟大值
 */

// @lc code=start
#include <algorithm>
#include <map>

class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
        if (nums.size() <= 1) return 0;
        std::map<int, int> num_cnt;
        for (auto num : nums) {
            num_cnt[num]++;
        }

        int pre_bigger_cnt = 0;
        int result = 0;
        for (auto it = num_cnt.rbegin(); it != num_cnt.rend(); it++) {
            if (pre_bigger_cnt > it->second) {
                result += it->second;
                pre_bigger_cnt -= it->second;
            } else {
                result += pre_bigger_cnt;
                pre_bigger_cnt = 0;
            }
            pre_bigger_cnt += it->second;
        }
        return result;
    }
};
// @lc code=end

