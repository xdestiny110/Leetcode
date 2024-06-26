/*
 * @lc app=leetcode.cn id=575 lang=cpp
 *
 * [575] 分糖果
 */

// @lc code=start

#include <algorithm>
#include <vector>
#include <unordered_set>

class Solution {
public:
    int distributeCandies(std::vector<int>& candyType) {
        std::unordered_set<int> unique_candy_type(candyType.begin(),candyType.end());
        return candyType.size() / 2 > unique_candy_type.size() ? unique_candy_type.size() : candyType.size() / 2;
    }
};
// @lc code=end

