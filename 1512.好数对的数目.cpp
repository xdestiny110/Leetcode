/*
 * @lc app=leetcode.cn id=1512 lang=cpp
 *
 * [1512] 好数对的数目
 */

// @lc code=start
#include <unordered_map>

class Solution {
public:
    int numIdenticalPairs(std::vector<int>& nums) {
        std::unordered_map<int, int> m;
        for(const auto& it : nums){
            auto jt = m.find(it);
            if(jt == m.end()){
                m[it] = 1;
            }
            else{
                jt->second++;
            }
        }

        int ret = 0;
        for(const auto& [k, v] : m){
            ret += v * (v-1) / 2;
        }
        return ret;
    }
};
// @lc code=end

