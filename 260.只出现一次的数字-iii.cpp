/*
 * @lc app=leetcode.cn id=260 lang=cpp
 *
 * [260] 只出现一次的数字 III
 */

// @lc code=start

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xXORy = 0;
        for(const auto& it : nums){
            xXORy ^= it;
        }

        // 找到这两个数在二进制上从哪一位开始不一样
        int diffBit = xXORy & (~(xXORy - 1));
        std::vector<int> r(2, 0);
        for(const auto& it : nums){
            if((it & diffBit) == 0){
                r[0] ^= it;
            }
            else{
                r[1] ^= it;
            }
        }

        return r;
    }
};
// @lc code=end

