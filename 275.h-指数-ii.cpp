/*
 * @lc app=leetcode.cn id=275 lang=cpp
 *
 * [275] H 指数 II
 */

// @lc code=start
#include <vector>

class Solution {
public:
    int hIndex(std::vector<int>& citations) {
        int head = 0;
        int tail = citations.size();
        while (head < tail - 1) {
            auto mid = (head + tail) / 2;
            auto cnt = paper_count(citations, mid);
            if (mid < cnt) {
                head = mid;
            } else {
                tail = mid;
            }
        }
        return paper_count(citations, tail) >= tail ? tail : head;
    }

private:
    int paper_count(const std::vector<int>& citations, int h) const {
        auto it = std::lower_bound(citations.begin(), citations.end(), h);
        return std::distance(it, citations.end());
    }

};
// @lc code=end

