/*
 * @lc app=leetcode.cn id=274 lang=cpp
 *
 * [274] H 指数
 */

// @lc code=start

#include <vector>
#include <algorithm>

class Solution {
public:
    int hIndex(std::vector<int>& citations) {
        std::sort(citations.begin(), citations.end());
        int head = 0;
        int tail = citations.size();
        while (head < tail - 1) {
            auto mid = (head + tail) / 2;
            auto cnt = paper_cnt(citations, mid);
            if (cnt == mid) return cnt;
            if (cnt > mid) {
                head = mid;
            } else {
                tail = mid;
            }
        }
        auto tail_cnt = paper_cnt(citations, tail);
        if (tail_cnt >= tail) return tail;
        return head;
    }

private:
    int paper_cnt(const std::vector<int>& citations, int h) const {
        auto it = std::lower_bound(citations.begin(), citations.end(), h);
        return std::distance(it, citations.end());
    }
};
// @lc code=end

