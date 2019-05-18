/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> m;
        for(int i = 0;i < nums.size(); i++){
            if(m.find(target-nums[i]) != m.end()){
                return vector<int>{ m[target-nums[i]], i };
            }
            else{
                m[nums[i]] = i;
            }
        }
        return vector<int>{};
    }
};

