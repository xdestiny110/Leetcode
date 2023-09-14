/*
 * @lc app=leetcode.cn id=630 lang=cpp
 *
 * [630] 课程表 III
 */

// @lc code=start
class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });
        priority_queue<int> q;
        int time = 0;
        for (auto& course : courses) {
            if (time + course[0] <= course[1]) {
                q.push(course[0]);
                time += course[0];
            } else if (!q.empty() && q.top() > course[0]) {
                time += course[0] - q.top();
                q.pop();
                q.push(course[0]);
            }
        }
        return q.size();
    }
};
// @lc code=end

