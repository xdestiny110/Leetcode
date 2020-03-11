/*
 * @lc app=leetcode.cn id=204 lang=cpp
 *
 * [204] 计数质数
 */

// @lc code=start

#include <cmath>
#include <vector>

class Solution {
public:
    int countPrimes(int n) {
        std::vector<int> s;
        for(int i = 2; i < n; ++i){
            bool flag = true;
            for(const auto& it : s){
                if(it > std::sqrt(i)){
                    break;
                }
                if(i % it == 0){
                    flag = false;
                    break;
                }
            }
            if(flag){
                s.emplace_back(i);
            }
        }
        return s.size();
    }
};
// @lc code=end

