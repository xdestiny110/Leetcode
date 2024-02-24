/*
 * @lc app=leetcode.cn id=1696 lang=cpp
 *
 * [1696] 跳跃游戏 VI
 */

// @lc code=start
#include <vector>
#include <map>

class Solution {
public:
    int maxResult(std::vector<int>& nums, int k) {
        std::map<int, int> m;
        std::queue<decltype(m)::iterator> q;
        m[nums[0]]++;
        q.push(m.begin());
        int current_max = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            current_max = m.rbegin()->first + nums[i];
            m[current_max]++;
            q.push(m.find(current_max));
            if (q.size() > k) {
                q.front()->second--;
                if (q.front()->second == 0) {
                    m.erase(q.front());
                }
                q.pop();
            }
        }
        return current_max;
    }
};
// @lc code=end

