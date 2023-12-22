/*
 * @lc app=leetcode.cn id=1901 lang=cpp
 *
 * [1901] 寻找峰值 II
 */

// @lc code=start

#include <vector>
#include <span>

class Solution {
public:
    std::vector<int> findPeakGrid(const std::vector<std::vector<int>>& mat) {
        return binarySearch(std::span{mat});
    }

private:
    template<typename T, size_t N>
    std::vector<int> binarySearch(std::span<T, N> submat){
        int mid = submat.size() / 2;
        auto max_it = std::max_element(submat[mid].begin(), submat[mid].end());
        int c = std::distance(submat[mid].begin(), max_it);
        if (submat.size() == 1) {
            return {0, c};
        }
        if (mid - 1 >= 0 && submat[mid - 1][c] > *max_it) {
            return binarySearch(submat.subspan(0, mid));
        }
        if (mid + 1 < submat.size() && submat[mid + 1][c] > *max_it) {
            auto ret = binarySearch(submat.subspan(mid + 1));
            ret[0] += mid + 1;
            return ret;
        }
        return {mid, c};
    }
};
// @lc code=end

