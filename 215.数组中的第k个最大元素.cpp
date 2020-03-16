/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */

// @lc code=start
#include <algorithm>
#include <vector>

class Solution {
public:
    int findKthLargest(std::vector<int>& nums, int k) {

        std::vector<int> heap;
        if(k > nums.size() / 2){
            k = nums.size() - k + 1;
            heap = std::vector<int>(nums.begin(), nums.begin() + k);
            std::make_heap(heap.begin(), heap.end());
            for(int i = k; i < nums.size(); ++i){
                if(nums[i] < heap[0]){
                    std::pop_heap(heap.begin(), heap.end());
                    heap.back() = nums[i];
                    std::push_heap(heap.begin(), heap.end());
                }
            }
        }
        else{
            heap = std::vector<int>(nums.begin(), nums.begin() + k);
            std::make_heap(heap.begin(), heap.end(), std::greater<>());
            for(int i = k; i < nums.size(); ++i){
                if(nums[i] > heap[0]){
                    std::pop_heap(heap.begin(), heap.end(), std::greater<>());
                    heap.back() = nums[i];
                    std::push_heap(heap.begin(), heap.end(), std::greater<>());
                }
            }
        }
        return heap[0];
    }
};
// @lc code=end

