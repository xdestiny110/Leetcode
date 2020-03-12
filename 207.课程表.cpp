/*
 * @lc app=leetcode.cn id=207 lang=cpp
 *
 * [207] 课程表
 */

// @lc code=start

#include <vector>
#include <unordered_map>
#include <unordered_set>

class Solution {
public:
    bool canFinish(int numCourses, std::vector<std::vector<int>>& prerequisites) {
        for(const auto& it : prerequisites){
            auto& v = m[it[0]];
            v.emplace_back(it[1]);
        }

        for(const auto& [k, v] : m){
            if(!DFS(k, {k})){
                return false;
            }
        }
        return true;
    }

private:
    std::unordered_map<int, std::vector<int>> m;
    bool DFS(int key, std::unordered_set<int>&& s){
        if(m.find(key) == m.end()) return true;
        for(const auto& it : m[key]){
            if(s.find(it) != s.end()) return false;
            s.insert(it);
            if(!DFS(it, std::move(s))) return false;
            s.erase(it);
        }
        return true;
    }
};
// @lc code=end

