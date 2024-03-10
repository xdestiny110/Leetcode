/*
 * @lc app=leetcode.cn id=2917 lang=cpp
 *
 * [2917] 找出数组中的 K-or 值
 */

// @lc code=start
class Solution {
public:
    int findKOr(vector<int>& nums, int k) {
        std::vector<std::bitset<32>> nums_bits;
        for (auto num : nums) {
            nums_bits.emplace_back(num);
        }

        std::bitset<32> result;
        for (int i = 0; i <= 31; ++i) {
            int count = 0;
            for (const auto& bit_num : nums_bits) {
                if (bit_num[i] == 1) {
                    count++;
                }
            }
            if (count >= k) {
                result[i] = 1;
            }
        }

        return result.to_ulong();        
    }
};
// @lc code=end

