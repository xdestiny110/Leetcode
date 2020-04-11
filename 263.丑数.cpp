/*
 * @lc app=leetcode.cn id=263 lang=cpp
 *
 * [263] 丑数
 */

// @lc code=start
class Solution {
public:
    bool isUgly(int num) {
        std::vector<int> factor = {2, 3, 5};
        for(const auto& it : factor){
            while(num > 1 && num % it == 0){
                num /= it;
            }
        }
        return num == 1;
    }
};
// @lc code=end

