/*
 * @lc app=leetcode.cn id=2661 lang=cpp
 *
 * [2661] 找出叠涂元素
 */

// @lc code=start

#include <vector>
#include <unordered_map>
#include <unordered_set>

class Solution {
public:
    int firstCompleteIndex(std::vector<int>& arr, std::vector<std::vector<int>>& mat) {
        std::unordered_map<int, std::pair<int, int>> num_rowcol;
        std::unordered_map<int, std::unordered_set<int>> row_nums;
        std::unordered_map<int, std::unordered_set<int>> col_nums;

        for (int r = 0; r < mat.size(); ++r) {
            for (int c = 0; c < mat[r].size(); ++c) {
                row_nums[r].insert(mat[r][c]);
                col_nums[c].insert(mat[r][c]);
                num_rowcol[mat[r][c]] = {r, c};
            }
        }

        for (int i = 0; i < arr.size(); ++i) {
            auto [r, c] = num_rowcol[arr[i]];
            row_nums[r].erase(arr[i]);
            col_nums[c].erase(arr[i]);
            if (row_nums[r].empty() || col_nums[c].empty()) {
                return i;
            }
        }
        return -1;
    }
};
// @lc code=end

