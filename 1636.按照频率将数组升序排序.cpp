/*
 * @lc app=leetcode.cn id=1636 lang=cpp
 *
 * [1636] 按照频率将数组升序排序
 */

// @lc code=start
#include <map>
#include <set>
#include <vector>

class Solution {
public:
    std::vector<int> frequencySort(std::vector<int>& nums) {
        std::map<int, int> mValFreq;
        std::map<int, std::set<int, std::greater<int>>> mFreqVal;
        for(const auto& it : nums){
            auto jt = mValFreq.find(it);
            if(jt == mValFreq.end()){
                mValFreq[it] = 1;
            }
            else{
                jt->second++;
            }
        }

        for(const auto& it : mValFreq){
            auto jt = mFreqVal.find(it.second);
            if(jt == mFreqVal.end()){
                mFreqVal[it.second] = {it.first};
            }
            else{
                mFreqVal[it.second].insert(it.first);
            }
        }

        std::vector<int> ret;
        for(const auto& it : mFreqVal){
            for(const auto& jt : it.second){
                ret.insert(ret.end(), it.first, jt);
            }
        }
        return ret;
    }
};
// @lc code=end

