/*
 * @lc app=leetcode.cn id=2048 lang=cpp
 *
 * [2048] 下一个更大的数值平衡数
 */

// @lc code=start

#include <string>
#include <unordered_map>

class Solution {
public:
    int nextBeautifulNumber(int n) {
        auto n_str = std::to_string(n);
        int first_num = n_str[0] - '0';
        int len = n_str.size();        

        std::unordered_map<int, int> digit_cnt;
        for (int i = n + 1;;++i) {
            auto num = i;
            bool flag = true;
            while (num > 0) {
                auto n = num % 10;
                if (n > len + 1) {
                    flag = false;
                    break;
                }
                digit_cnt[num % 10]++;
                num /= 10;
            }
            if (flag) {
                for (auto [d, c] : digit_cnt) {
                    if (d != c) {
                        flag = false;
                        break;
                    }
                }
            }
            if (flag) {
                return i;
            }
            digit_cnt.clear();
        }
        return -1;
    }
};
// @lc code=end

