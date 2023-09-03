/*
 * @lc app=leetcode.cn id=690 lang=cpp
 *
 * [690] 员工的重要性
 */

// @lc code=start
/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

#include <vector>
#include <unordered_map>

class Solution {
public:
    int getImportance(std::vector<Employee*> employees, int id) {
        std::unordered_map<int, Employee*> all_employee;
        for (auto employee : employees) {
            all_employee[employee->id] = employee;
        }

        return dfs(id, all_employee);
    }

private:
    int dfs(int id, const std::unordered_map<int, Employee*>& all_employee) const {
        auto result = all_employee.at(id)->importance;
        for (auto sub_id : all_employee.at(id)->subordinates) {
            result += dfs(sub_id, all_employee);
        }
        return result;
    }

};
// @lc code=end

