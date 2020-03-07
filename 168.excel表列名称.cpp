/*
 * @lc app=leetcode.cn id=168 lang=cpp
 *
 * [168] Excel表列名称
 */

// @lc code=start
#include <string>

class Solution {
public:
    std::string convertToTitle(int n) {
        std::string r;
        while(n > 26){
            n--;
            auto nMod = n % 26;
            n /= 26;
            r.insert(r.begin(), 'A' + nMod);
        }
        n--;
        r.insert(r.begin(), 'A' + n);
        return r;
    }
};
// @lc code=end

