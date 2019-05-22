/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        std::vector<std::vector<int>> ret;
        if(nums.size() < 4)
            return ret;
        
        std::sort(nums.begin(), nums.end());
        for(int i = 0;i < nums.size()-3;i++){
            if(i > 0 && nums[i] == nums[i-1])
                continue;
            for(int j = i+1;j < nums.size()-2;j++){
                if(j > i+1 && nums[j] == nums[j-1])
                    continue;
                int front = j+1;
                int tail = nums.size()-1;
                while(front < tail){
                    if(front != j+1 && nums[front] == nums[front-1]){
                        front++;
                        continue;
                    }
                    if(tail != nums.size()-1 && nums[tail] == nums[tail+1])
                    {
                        tail--;
                        continue;
                    }
                        
                    int sum = nums[i]+nums[j]+nums[front]+nums[tail];
                    if(sum == target){
                        ret.emplace_back(std::vector<int>{nums[i], nums[j], nums[front], nums[tail]});
                        front++;
                        tail--;
                    }
                    else{
                        if(sum > target)
                            tail--;
                        else
                            front++;
                    }
                }
            }
        }
        return ret;
    }
};

