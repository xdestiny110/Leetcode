/*
 * @lc app=leetcode.cn id=1647 lang=cpp
 *
 * [1647] 字符频次唯一的最小删除次数
 */

// @lc code=start
#include <vector>
#include <map>
#include <string>
#include <algorithm>

class Solution {
public:
    int minDeletions(std::string s) {
        std::map<char, int> mValFreq;
        for(const auto& it : s){
            auto jt = mValFreq.find(it);
            if(jt == mValFreq.end()){
                mValFreq.emplace(it, 1);
            }
            else{
                jt->second++;
            }
        }

        std::vector<int> mFreqCnt;
        for(const auto& it : mValFreq){
           mFreqCnt.emplace_back(it.second);
        }
        if(mFreqCnt.size() <= 1) return 0;
        std::sort(mFreqCnt.begin(), mFreqCnt.end(), std::greater<>());

        bool flag = false;
        int baseNum = -1;
        int opTimes = 0;
        for(int i = 1; i < mFreqCnt.size(); ++i){
            if(flag){
                if(mFreqCnt[i] >= baseNum){
                    baseNum = std::max(0, baseNum - 1);
                    opTimes += mFreqCnt[i] - baseNum;
                }
                else{
                    baseNum = std::min(baseNum, mFreqCnt[i]);
                }
            }
            else{
                if(mFreqCnt[i] == mFreqCnt[i-1]){
                    flag = true;
                    baseNum = mFreqCnt[i] - 1;
                    opTimes++;
                }
            }
        }
        return opTimes;
    }
};
// @lc code=end

