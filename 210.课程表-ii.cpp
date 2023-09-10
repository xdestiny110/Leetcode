/*
 * @lc app=leetcode.cn id=210 lang=cpp
 *
 * [210] 课程表 II
 */

// @lc code=start

#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>

class Solution {
public:
    std::vector<int> findOrder(int numCourses, std::vector<std::vector<int>>& prerequisites) {
        std::unordered_map<int, std::unordered_set<int>> course_deps;
        std::unordered_map<int, std::unordered_set<int>> course_posts;
        for (int i = 0; i < numCourses; ++i) {
            course_deps[i] = {};
            course_posts[i] = {};
        }

        for (const auto& pres : prerequisites) {
            course_deps[pres[0]].insert(pres[1]);
            course_posts[pres[1]].insert(pres[0]);
        }

        std::queue<int> indegree_zero_courses;
        for (int i = 0; i < numCourses; ++i) {
            if (course_deps[i].empty()) {
                indegree_zero_courses.push(i);
            }
        }

        std::vector<int> result;
        while (!indegree_zero_courses.empty()) {
            auto course = indegree_zero_courses.front();
            result.push_back(course);
            indegree_zero_courses.pop();
            for (auto course_post : course_posts[course]) {
                course_deps[course_post].erase(course);
                if (course_deps[course_post].empty()) {
                    indegree_zero_courses.push(course_post);
                }
            }
            course_posts.erase(course);
        }

        return course_posts.empty() ? result : std::vector<int>{};
    }
};
// @lc code=end

