/*
 * @lc app=leetcode.cn id=1646 lang=cpp
 *
 * [1646] 获取生成数组中的最大值
 */

// @lc code=start
class Solution {
public:
    int getMaximumGenerated(int n) {
        if(n == 0) return 0;
        if(n == 1) return 1;
        std::vector<int> v(n + 1);
        v[0] = 0;v[1] = 1;
        for(int i = 2; i <= n; ++i){
            v[i] = (i % 2) ? v[i / 2] + v[i / 2 + 1] : v[i / 2];
        }
        return *std::max_element(v.begin(), v.end());
    }
};
// @lc code=end

