/*
 * @lc app=leetcode.cn id=1738 lang=cpp
 *
 * [1738] 找出第 K 大的异或坐标值
 */

// @lc code=start

#include <queue>
#include <vector>

class Solution {
public:
    int kthLargestValue(std::vector<std::vector<int>>& matrix, int k) {
        size_t m = matrix.size();
        size_t n = matrix[0].size();
        std::vector<std::vector<int>> xor_result(m, std::vector<int>(n));
        std::priority_queue<int, std::vector<int>, std::greater<>> q;
        xor_result[0][0] = matrix[0][0];
        q.push(xor_result[0][0]);
        for (size_t r = 1; r < m; ++r) {
            xor_result[r][0] = xor_result[r - 1][0] ^ matrix[r][0];
            q.push(xor_result[r][0]);
            if (q.size() > k) {
                q.pop();
            }
        }
        for (size_t c = 1; c < n; ++c) {
            xor_result[0][c] = xor_result[0][c - 1] ^ matrix[0][c];
            q.push(xor_result[0][c]);
            if (q.size() > k) {
                q.pop();
            }
        }
        for (size_t r = 1; r < m; ++r) {
            for (size_t c = 1; c < n; ++c) {
                xor_result[r][c] = xor_result[r - 1][c - 1] ^ xor_result[r - 1][c] ^ xor_result[r][c - 1] ^ matrix[r][c];
                q.push(xor_result[r][c]);
                if (q.size() > k) {
                    q.pop();
                }
            }
        }
        return q.top();
    }
};
// @lc code=end

