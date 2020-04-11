/*
 * @lc app=leetcode.cn id=264 lang=cpp
 *
 * [264] 丑数 II
 */

// @lc code=start

#include <vector>
#include <algorithm>

class Solution {
public:
    int nthUglyNumber(int n) {
        std::vector<int> result = {1};
        result.reserve(n);
        std::vector<int> record(3, 0);

        std::vector<int> factor = {2, 3, 5};
        std::vector<int> t(3, 0);
        std::vector<int> minIdx;
        minIdx.reserve(3);
        while(result.size() < n){
            int minNum = std::numeric_limits<int>::max();
            for(int i = 0; i < 3; ++i){
                t[i] = factor[i] * result[record[i]];
                if(t[i] <= minNum){
                    if(t[i] == minNum){
                        minIdx.emplace_back(i);
                    }
                    else{
                        minIdx.clear();
                        minIdx.emplace_back(i);
                        minNum = t[i];
                    }
                }
            }

            for(const auto& it : minIdx){
                record[it]++;
            }
            minIdx.clear();
            result.emplace_back(minNum);
        }

        return result.back();
    }
};
// @lc code=end

