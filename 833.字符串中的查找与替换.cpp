/*
 * @lc app=leetcode.cn id=833 lang=cpp
 *
 * [833] 字符串中的查找与替换
 */

// @lc code=start
#include <string>
#include <vector>
#include <unordered_map>
#include <numeric>

using namespace std;

class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        std::vector<std::string> v_s;
        for (size_t i = 0; i < s.size(); ++i) {
            v_s.emplace_back(1, s[i]);
        }

        for (size_t i = 0; i < indices.size(); ++i) {
            if (indices[i] + sources[i].size() > s.size()) continue;
            if (s.substr(indices[i], sources[i].size()) == sources[i]) {
                v_s[indices[i]] = targets[i];
                for (size_t j = indices[i] + 1; j < indices[i] + 1 + sources[i].size() - 1; ++j) {
                    v_s[j].clear();
                }
            }
        }

        std::string ret;
        for (const auto& str : v_s) {
            ret += str;
        }
        return ret;
    }
};
// @lc code=end

