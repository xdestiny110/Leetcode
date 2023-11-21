/*
 * @lc app=leetcode.cn id=2342 lang=cpp
 *
 * [2342] 数位和相等数对的最大和
 */

// @lc code=start
#include <vector>
#include <queue>
#include <unordered_map>
#include <numeric>

class Solution {
public:
    int maximumSum(const std::vector<int>& nums) const {
        std::unordered_map<int, std::pair<std::priority_queue<int, std::vector<int>, std::greater<int>>, int>> m;
        for (auto num : nums) {
            auto sum = digit_sum(num);
            if (auto it = m.find(sum); it != m.end()) {
                if (it->second.first.size() == 2 && it->second.first.top() < num) {
                    it->second.second -= it->second.first.top();
                    it->second.first.pop();
                }
                if (it->second.first.size() < 2) {
                    it->second.first.push(num);
                    it->second.second += num;
                }
            } else {
                m[sum].first.push(num);
                m[sum].second = num;
            }
        }
        int result = -1;
        for (const auto& [_, q_sum] : m) {
            if (q_sum.first.size() == 2) {
                result = std::max(result, q_sum.second);
            }
        }
        return result;
    }

private:
    int digit_sum(int num) const {
        int result = 0;
        while (num > 0) {
            result += num % 10;
            num /= 10;
        }
        return result;
    }
};
// @lc code=end

