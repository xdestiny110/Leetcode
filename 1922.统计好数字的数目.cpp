/*
 * @lc app=leetcode.cn id=1922 lang=cpp
 *
 * [1922] 统计好数字的数目
 */

// @lc code=start
#include <cmath>
#include <cstddef>
#include <string>

class Solution {
public:
    int countGoodNumbers(long long n) {
        auto num1 = pow_fast(4, n / 2);
        auto num2 = pow_fast(5, n / 2 + n % 2);
        return multiply_mod(num1, num2);
    }

private:
    static constexpr int mod_num = 1'000'000'007;

    uint64_t pow_fast(uint64_t a, uint64_t b) const {
        uint64_t result = 1;
        while (b > 0) {
            if (b % 2 > 0) {
                result = multiply_mod(result, a);
            }
            a = multiply_mod(a, a);
            b /= 2;
        }
        return result;
    }

    uint64_t multiply_mod(uint64_t a, uint64_t b) const {
        return ((a % mod_num) * (b % mod_num)) % mod_num;
    }
};
// @lc code=end

