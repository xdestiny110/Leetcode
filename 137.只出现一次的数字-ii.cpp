/*
 * @lc app=leetcode.cn id=137 lang=cpp
 *
 * [137] 只出现一次的数字 II
 */

// @lc code=start
class Solution {
public:
    int singleNumber(vector<int>& nums) {
         // 设置计数器,以及标记变量
        int a = 0, b = 0, mark = 1;
        // 遍历原始数组,统计各个bit位上数值1出现的次数
        for (int num : nums) {
            a ^= b & num;
            b ^= num;
            // 计算标记变量mark,更新计数器的值,若达到循环点3(即a=1,b=1),则将计数器对应bit位置为0,否则保持不变
            mark = ~(a & b);
            a &= mark;
            b &= mark;
        }
        // 由于本题中,待查找数出现次数为奇数次,因此只要每个bit位的最低计数位为1,则待查找数对应bit位也为1
        return b;
    }
};
// @lc code=end

