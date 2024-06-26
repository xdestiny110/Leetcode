/*
 * @lc app=leetcode.cn id=1673 lang=cpp
 *
 * [1673] 找出最具竞争力的子序列
 */

// @lc code=start

#include <set>
#include <vector>

struct IdxNum {
    size_t idx_;
    int num_;

    bool operator<(const IdxNum& rhs) const {
        return num_ < rhs.num_ || (num_ == rhs.num_ && idx_ < rhs.idx_);
    }
};

class Solution {
public:
    std::vector<int> mostCompetitive(std::vector<int>& nums, int k) {
        std::vector<IdxNum> v;
        for (size_t idx = 0; idx < nums.size() - k + 1; ++idx) {
            v.push_back(IdxNum {
                .idx_ = idx,
                .num_ = nums[idx],
            });
        }
        std::set<IdxNum> s(v.begin(), v.end());
        std::vector<int> result;
        result.reserve(k);
        for (size_t i = 0; i < k; ++i) {
            auto t = *s.begin();
            result.push_back(t.num_);
            for (size_t j = 0; j <= t.idx_; ++j) {
                s.erase(IdxNum {
                    .idx_ = j,
                    .num_ = nums[j],
                });
            }

            for (size_t j = t.idx_; j < t.idx_ + i - 1; ++j) {
                s.insert(IdxNum {
                    .idx_ = j,
                    .num_ = nums[j],
                });
            }
        }
        return result;
    }
};
// @lc code=end

