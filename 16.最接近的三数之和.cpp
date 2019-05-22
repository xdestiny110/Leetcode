/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
 */
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end());
        int minDiff = std::numeric_limits<int>::max();
        int minSum = 0;
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
                int diff = abs(sum-target);
                if(diff == 0)
                    return sum;
                else{
                    if(minDiff > diff){
                        minDiff = diff;
                        minSum = sum;
                    }
                    if(sum-target > 0)
                        tail--;
                    else
                        front++;
                }
            }
        }
        return minSum;
    }
};

