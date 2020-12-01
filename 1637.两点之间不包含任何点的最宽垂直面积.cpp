/*
 * @lc app=leetcode.cn id=1637 lang=cpp
 *
 * [1637] 两点之间不包含任何点的最宽垂直面积
 */

// @lc code=start
#include <vector>
#include <set>
#include <algorithm>

class Solution {
public:
    int maxWidthOfVerticalArea(std::vector<std::vector<int>>& points) {
        std::set<int> s;
        for(const auto& it : points){
            s.insert(it[0]);
        }

        if(s.size() <= 1) return 0;
        auto it = s.begin(), jt = s.begin();
        it++;
        int maxArea = 0;
        for(; it != s.end(); ++it, ++jt){
            maxArea = std::max(maxArea, *it - *jt);
        }
        return maxArea;
    }
};
// @lc code=end

