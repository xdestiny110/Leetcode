/*
 * @lc app=leetcode.cn id=1462 lang=cpp
 *
 * [1462] 课程表 IV
 */

// @lc code=start
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>

class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, const std::vector<std::vector<int>>& prerequisites, const std::vector<std::vector<int>>& queries) {
        std::unordered_map<int, std::unordered_set<int>> course_pres;
        for (const auto& pre : prerequisites) {
            course_pres[pre[1]].insert(pre[0]);
        }
        std::unordered_map<int, std::unordered_set<int>> course_all_pres;
        for (const auto& [course, pres] : course_pres) {
            std::queue<int> q;
            for (auto pre : pres) {
                q.push(pre);
            }
            while (!q.empty()) {
                auto c = q.front();
                q.pop();
                if (course_all_pres[course].contains(c)) {
                    continue;
                }
                course_all_pres[course].insert(c);
                if (course_pres.contains(c)) {
                    for (auto pre : course_pres[c]) {
                        q.push(pre);
                    }
                }
            }
        }
        

        std::vector<bool> result;
        for (const auto& query : queries) {
            result.push_back(course_all_pres[query[1]].contains(query[0]));
        }
        return result;
    }
};
// @lc code=end

