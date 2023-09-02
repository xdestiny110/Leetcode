/*
 * @lc app=leetcode.cn id=692 lang=cpp
 *
 * [692] 前K个高频单词
 */

// @lc code=start

#include <vector>
#include <string>
#include <queue>
#include <unordered_map>

class Solution {
    using Pair = std::pair<std::string, size_t>;
public:
    std::vector<std::string> topKFrequent(std::vector<std::string>& words, int k) {
        std::unordered_map<std::string, size_t> word_cnt;
        for (const auto& word : words) {
            word_cnt[word]++;
        }

        auto pair_cmp = [](const Pair& lhs, const Pair& rhs) {
            return (lhs.second > rhs.second) || (lhs.second == rhs.second && lhs.first < rhs.first);
        };
        std::priority_queue<Pair, std::vector<Pair>, decltype(pair_cmp)> q(pair_cmp);
        for (const auto& [word, cnt] : word_cnt) {
            q.push({word, cnt});
            while (q.size() > k) {
                q.pop();
            }
        }

        std::vector<std::string> result;
        while (!q.empty()) {
            result.push_back(q.top().first);
            q.pop();
        }
        std::reverse(result.begin(), result.end());
        return result;
    }
};
// @lc code=end

