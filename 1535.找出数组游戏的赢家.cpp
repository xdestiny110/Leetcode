/*
 * @lc app=leetcode.cn id=1535 lang=cpp
 *
 * [1535] 找出数组游戏的赢家
 */

// @lc code=start

#include <vector>

class Solution {
public:
    int getWinner(std::vector<int>& arr, int k) {
        int current_k = 1;
        int current_max = std::max(arr[0], arr[1]);
        if (k == 1) return current_max;
        for (size_t i = 2; i < arr.size(); ++i) {
            if (current_max > arr[i]) {
                current_k++;
                if (current_k >= k) {
                    return current_max;
                }
            } else {
                current_max = arr[i];
                current_k = 1;
            }
        }
        return current_max;
    }
};
// @lc code=end

