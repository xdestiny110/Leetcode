/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::vector<std::vector<int>> ret;
        if(nums.size() < 3)
            return ret;
        std::sort(nums.begin(), nums.end());
        for(int i = 0;i < nums.size()-2;i++){
            if(i > 0 && nums[i] == nums[i-1])
                continue;
            int front = i+1;
            int tail = nums.size()-1;
            while(front < tail){
                if(front != i+1 && nums[front] == nums[front-1]){
                    front++;
                    continue;
                }
                if(tail != nums.size()-1 && nums[tail] == nums[tail+1]){
                    tail--;
                    continue;
                }
                int sum = nums[i]+nums[front]+nums[tail];
                if(sum == 0){
                    ret.emplace_back(std::vector<int>{nums[i], nums[front], nums[tail]});
                    front++;
                    tail--;
                }
                else{
                    if(sum > 0)
                        tail--;
                    else
                        front++;
                }
            }
        }
        return ret;
    }
};
