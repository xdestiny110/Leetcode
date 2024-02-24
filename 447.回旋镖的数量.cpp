/*
 * @lc app=leetcode.cn id=447 lang=cpp
 *
 * [447] 回旋镖的数量
 */

// @lc code=start

#include <vector>
#include <unordered_map>

class Solution {
public:
    int numberOfBoomerangs(std::vector<std::vector<int>>& points) {
        // { point_idx : { length : [point_idx] } }
        std::unordered_map<int, std::unordered_map<long long, std::vector<int>>> m;
        for (int i = 0; i < points.size(); ++i) {
            for (int j = i + 1; j < points.size(); ++j) {
                long long dist = calc_dist(points[i], points[j]);
                m[i][dist].push_back(j);
                m[j][dist].push_back(i);
            }
        }

        int result = 0;
        for (int i = 0; i < points.size(); ++i) {
            for (int j = 0; j < points.size(); ++j) {
                if (i == j) continue;
                long long dist = calc_dist(points[i], points[j]);
                result += m[i][dist].size() - 1;
            }
        }
        return result;
    }

private:
    long long calc_dist(const std::vector<int>& a, const std::vector<int>& b) const {
        return (a[0] - b[0]) * (a[0] - b[0]) + (a[1] - b[1]) * (a[1] - b[1]);
    }
};
// @lc code=end

