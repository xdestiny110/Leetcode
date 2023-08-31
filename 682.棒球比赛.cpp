/*
 * @lc app=leetcode.cn id=682 lang=cpp
 *
 * [682] 棒球比赛
 */

// @lc code=start

#include <string>
#include <vector>
#include <numeric>

class Solution {
public:
    int calPoints(std::vector<std::string>& operations) {
        std::vector<int> record;
        for (const auto& op : operations) {
            if (op == "C") {
                record.pop_back();
            } else if (op == "D") {
                record.push_back(record.back() * 2);
            } else if (op == "+") {
                record.push_back(record.back() + record[record.size() - 2]);
            } else {
                record.push_back(std::stoi(op));
            }
        }
        return std::accumulate(record.begin(), record.end(), 0);
    }
};
// @lc code=end

