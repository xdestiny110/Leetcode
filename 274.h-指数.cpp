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
        int head = 0;
        int tail = citations.size();
        while (head < tail - 1) {
            auto mid = (head + tail) / 2;
            if (citations[mid] < h) {
                head = mid;
            } else {
                tail = mid;
            }
        }
        return citations[head] >= h ? citations.size() - head : citations.size() - tail;
    }
};
// @lc code=end

