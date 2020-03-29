/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */

// @lc code=start
#include <vector>
#include <limits>
#include <deque>
#include <queue>

class Solution {
public:
    std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k) {
        if(k >= nums.size()) return {*std::max_element(nums.begin(), nums.end())};
        if(k == 1) return nums;
        std::deque<int> windowMax;
        std::queue<int> window;

        windowMax.push_back(nums[0]);
        window.push(nums[0]);
        for(int i = 1; i < k; ++i){
            while(!windowMax.empty() && windowMax.back() < nums[i]){
                windowMax.pop_back();
            }
            windowMax.push_back(nums[i]);
            window.push(nums[i]);
        }

        std::vector<int> ret;
        ret.reserve(nums.size() - k + 1);
        for(int i = k; i < nums.size(); ++i){
            ret.emplace_back(windowMax.front());
            if(windowMax.front() == window.front()){
                windowMax.pop_front();
            }
            window.pop();
            while(!windowMax.empty() && windowMax.back() < nums[i]){
                windowMax.pop_back();
            }
            windowMax.push_back(nums[i]);
            window.push(nums[i]);
        }
        
        ret.emplace_back(windowMax.front());
        return ret;
    }
};
// @lc code=end

