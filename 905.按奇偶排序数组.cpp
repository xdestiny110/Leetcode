/*
 * @lc app=leetcode.cn id=905 lang=cpp
 *
 * [905] 按奇偶排序数组
 */

// @lc code=start
#include <vector>

class Solution {
public:
    std::vector<int> sortArrayByParity(std::vector<int>& nums) {
        int head = 0;
        int tail = nums.size() - 1;

        while (head < tail) {
            while (head < nums.size()) {
                if (nums[head] % 2 > 0) {
                    break;
                }
                head++;
            }
            while (tail > 0) {
                if (nums[tail] % 2 == 0) {
                    break;
                }
                tail--;
            }
            if (head >= tail) {
                break;
            }
            std::swap(nums[head], nums[tail]);
            head++;
            tail--;
        }

        return nums;
    }
};
// @lc code=end

