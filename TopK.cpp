#include <iostream>
#include <vector>
#include <algorithm>

int quickSearch(std::vector<int>& nums, int k, int left, int right){
    auto l = left, r = right;
    while(l < r){
        while(l < r && nums[r] >= nums[left]) r--;
        while(l < r && nums[l] <= nums[left]) l++;
        if(l < r) std::swap(nums[l], nums[r]);
    }
    std::swap(nums[left], nums[l]);
    if(right - l + 1 == k){
        return nums[l];
    }
    else if(right - l + 1 > k){
        return quickSearch(nums, k, l + 1, right);
    }
    return quickSearch(nums, k - (right - l + 1), left, l - 1);
}

int main(int argc, char** argv){
    std::vector<int> nums = {6, 1, 2, 7, 9, 3, 4, 5, 10, 8};
    int k = 3;
    std::cout << quickSearch(nums, k, 0, nums.size() - 1) << std::endl;
    
    std::sort(nums.begin(), nums.end(), std::greater<>());
    std::cout << nums[k] << std::endl;
}