/*
 * @lc app=leetcode.cn id=2586 lang=cpp
 *
 * [2586] 统计范围内的元音字符串数
 */

// @lc code=start

#include <vector>
#include <string>
#include <unordered_set>

class Solution {
public:
    int vowelStrings(std::vector<std::string>& words, int left, int right) {
        std::unordered_set<char> aeiou = {'a', 'e', 'i', 'o', 'u'};
        int result = 0;
        for (int i = left; i <= right; ++i) {
            if (aeiou.contains(words[i].front()) && aeiou.contains(words[i].back())) {
                result++;
            }
        }
        return result;
    }
};
// @lc code=end

