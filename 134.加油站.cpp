/*
 * @lc app=leetcode.cn id=134 lang=cpp
 *
 * [134] 加油站
 */

// @lc code=start
#include <vector>
#include <algorithm>

class Solution {
public:
    int canCompleteCircuit(std::vector<int>& gas, std::vector<int>& cost) {
        int sum = 0;
        int currentSum = 0;
        int start = 0;
        for(int i = 0; i < gas.size(); ++i){
            sum += gas[i] - cost[i];
            currentSum += gas[i] - cost[i];
            if(currentSum < 0){
                start = (i + 1) % gas.size();
                currentSum = 0;
            }
        }

        return (sum < 0) ? -1 : start;
    }
};
// @lc code=end

