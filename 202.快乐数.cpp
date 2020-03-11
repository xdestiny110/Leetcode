/*
 * @lc app=leetcode.cn id=202 lang=cpp
 *
 * [202] 快乐数
 */

// @lc code=start
#include <unordered_set>

class Solution {
public:
    bool isHappy(int n) {
        std::unordered_set<long long> s;
        while(n != 1){
            if(s.find(n) != s.end()){
                return false;
            }
            s.insert(n);
            long long sum = 0;
            while(n > 0){
                sum += (n % 10) * (n % 10);
                n /= 10;
            }
            n = sum;
        }
        return true;
    }
};
// @lc code=end

