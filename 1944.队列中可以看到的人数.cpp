/*
 * @lc app=leetcode.cn id=1944 lang=cpp
 *
 * [1944] 队列中可以看到的人数
 */

// @lc code=start

#include <vector>
#include <stack>

class Solution {
public:
    std::vector<int> canSeePersonsCount(std::vector<int>& heights) {
        std::vector<int> result(heights.size(), 0);
        std::stack<int> s;
        for (int i = heights.size() - 1; i >= 0; --i) {
            int s_cnt_before_pop = s.size();
            while (!s.empty() && s.top() < heights[i]) {
                s.pop();
            }
            result[i] += s_cnt_before_pop - s.size();
            result[i] += s.empty() ? 0 : 1;
            s.push(heights[i]);
        }
        return result;
    }
};
// @lc code=end

