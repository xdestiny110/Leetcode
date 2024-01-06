/*
 * @lc app=leetcode.cn id=1954 lang=cpp
 *
 * [1954] 收集足够苹果的最小花园周长
 */

// @lc code=start

template<size_t N = 62997>
consteval auto pre_calc_apple_cnt() {
    std::array<long long, N> result = {};
    for (long long i = 1; i < N;++i) {
        result[i] = 2 * i * (i + 1) * (2 * i + 1);
    }
    return result;
}

class Solution {
public:
    long long minimumPerimeter(long long neededApples) {
        constinit static auto pre_calc_arr = pre_calc_apple_cnt<>();
        static_assert(pre_calc_arr.size() == 62997);
        auto it = std::lower_bound(pre_calc_arr.begin(), pre_calc_arr.end(), neededApples);
        return std::distance(pre_calc_arr.begin(), it) * 8;
    }
};
// @lc code=end

