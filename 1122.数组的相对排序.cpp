/*
 * @lc app=leetcode.cn id=1122 lang=cpp
 *
 * [1122] 数组的相对排序
 */

// @lc code=start
#include <vector>
#include <unordered_map>
#include <map>

class Solution {
public:
    std::vector<int> relativeSortArray(std::vector<int>& arr1, std::vector<int>& arr2) {
        std::unordered_map<int, int> record;
        for (auto num : arr1) {
            record[num]++;
        }

        std::vector<int> result;
        for (auto arr : arr2) {
            result.insert(result.end(), record[arr], arr);
            record.erase(arr);
        }

        std::map<int, int> sort_record;
        for (auto [num, cnt] : record) {
            sort_record[num] = cnt;
        }
        for (auto [num, cnt] : sort_record) {
            result.insert(result.end(), cnt, num);
        }
        return result;
    }
};
// @lc code=end

