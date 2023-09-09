/*
 * @lc app=leetcode.cn id=207 lang=cpp
 *
 * [207] 课程表
 */

// @lc code=start

#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>

class Solution {
public:
    bool canFinish(int numCourses, std::vector<std::vector<int>>& prerequisites) {
        std::unordered_map<int, std::unordered_set<int>> course_deps;
        for (int i = 0; i < numCourses; ++i) {
            course_deps[i] = {};
        }
        for (const auto& pres : prerequisites) {
            course_deps[pres[0]].insert(pres[1]);
        }

        std::map<int, std::unordered_set<int>> indegree_course;
        std::unordered_map<int, std::unordered_set<int>> course_after;
        for (const auto& [course, pres] : course_deps) {
            indegree_course[pres.size()].insert(course);
            for (auto pre : pres) {
                course_after[pre].insert(course);
            }
        }

        while (!indegree_course.empty() && !indegree_course[0].empty()) {
            for (auto course : indegree_course[0]) {
                for (auto after : course_after[course]) {
                    course_deps[after].erase(course);
                }
                course_deps.erase(course);
            }
            indegree_course.clear();
            for (const auto& [course, pres] : course_deps) {
                indegree_course[pres.size()].insert(course);
            }
        }

        return indegree_course.empty();
    }
};
// @lc code=end

