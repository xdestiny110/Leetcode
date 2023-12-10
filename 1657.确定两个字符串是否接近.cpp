/*
 * @lc app=leetcode.cn id=1657 lang=cpp
 *
 * [1657] 确定两个字符串是否接近
 */

// @lc code=start
#include <string>
#include <unordered_map>

class Solution {
public:
    bool closeStrings(std::string word1, std::string word2) {


        auto [cnt_times_1, char_cnt_1] = cal_cnt_times(word1);
        auto [cnt_times_2, char_cnt_2] = cal_cnt_times(word2);

        if (char_cnt_1.size() != char_cnt_2.size()) return false;
        for (const auto& [ch, cnt] : char_cnt_1) {
            if (!char_cnt_2.contains(ch)) {
                return false;
            }
        }

        if (cnt_times_1.size() != cnt_times_2.size()) return false;
        for (const auto& [cnt, times] : cnt_times_1) {
            if (cnt_times_2[cnt] != times) {
                return false;
            }
        }
        return true;
    }

private:
    std::pair<std::unordered_map<int, int>, std::unordered_map<char, int>> cal_cnt_times(const std::string& word) {
        std::unordered_map<char, int> char_cnt;
        for (auto c : word) {
            char_cnt[c]++;
        }
        std::unordered_map<int, int> cnt_times;
        for (const auto& [ch, cnt] : char_cnt) {
            cnt_times[cnt]++;
        }
        return {cnt_times,char_cnt};
    }
};
// @lc code=end

