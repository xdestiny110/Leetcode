/*
 * @lc app=leetcode.cn id=303 lang=cpp
 *
 * [303] 区域和检索 - 数组不可变
 */

// @lc code=start
#include <vector>

class NumArray {
public:
    NumArray(std::vector<int>& nums) : presum_(nums.size()) {
        presum_[0] = nums[0];
        for (size_t i = 1; i < nums.size(); ++i) {
            presum_[i] = presum_[i - 1] + nums[i];
        }
    }
    
    int sumRange(int left, int right) {
        return left == 0 ? presum_[right] : presum_[right] - presum_[left - 1];
    }

private:
    std::vector<uint64_t> presum_;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
// @lc code=end

