/*
 * @lc app=leetcode.cn id=2397 lang=cpp
 *
 * [2397] 被列覆盖的最多行数
 */

// @lc code=start
#include <vector>

class Solution {
public:
    int maximumRows(std::vector<std::vector<int>>& matrix, int numSelect) {
        int result_const = 0;
        std::vector<std::vector<int>> matrix_rest;
        for (const auto& r : matrix) {
            int one_count = std::count(r.begin(), r.end(), 1);
            if (one_count == 0) {
                result_const++;
            } else if (one_count <= numSelect) {
                matrix_rest.push_back(std::vector<int>(r.begin(), r.end()));
            }
        }

        std::vector<int> m(matrix[0].size(), 0);
        dfs(numSelect, -1, m, matrix_rest);
        return result + result_const;
    }

private:
    int result = 0;
    void dfs(int numSelect, int last_idx, std::vector<int>& m, const std::vector<std::vector<int>>& matrix) {
        if (numSelect == 0) {
            int t = 0;
            for (const auto& mat : matrix) {
                if (check(m, mat)) {
                    t++;
                }
            }
            result = std::max(result, t);
            return;
        }
        for (int i = last_idx + 1; i < m.size(); ++i) {
            m[i] = 1;
            dfs(numSelect - 1, i, m, matrix);
            m[i] = 0;
        }
    }

    bool check(const std::vector<int>& a, const std::vector<int>& b) const {
        for (int i = 0; i < a.size(); ++i) {
            if (a[i] == 0 && b[i] == 1) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

