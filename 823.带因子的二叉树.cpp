/*
 * @lc app=leetcode.cn id=823 lang=cpp
 *
 * [823] 带因子的二叉树
 */

// @lc code=start
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>

class Solution {
public:
    int numFactoredBinaryTrees(std::vector<int>& arr) {
        std::sort(arr.begin(), arr.end());
        std::unordered_map<int, uint64_t> record;
        record[arr[0]] = 1;
        constexpr int mod_num = 1000'000'007;

        for (size_t i = 1; i < arr.size(); ++i) {
            for (size_t j = 0; j < i; ++j) {
                if (arr[i] % arr[j] == 0 && record.find(arr[i] / arr[j]) != record.end()) {
                    auto num1 = record[arr[j]];
                    auto num2 = record[arr[i] / arr[j]];
                    record[arr[i]] += num1 * num2;
                }
            }
            record[arr[i]]++;
        }

        uint64_t result = 0;
        for (auto [num, cnt]: record) {
            result += cnt;
        }
        return result % mod_num;
    }
};
// @lc code=end

