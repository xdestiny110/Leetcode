/*
 * @lc app=leetcode.cn id=210 lang=cpp
 *
 * [210] 课程表 II
 */

// @lc code=start

#include <vector>
#include <unordered_map>
#include <unordered_set>

class Solution {
public:
    std::vector<int> findOrder(int numCourses, std::vector<std::vector<int>>& prerequisites) {
        s.reserve(numCourses);
        m.reserve(numCourses);
        for(int i = 0; i < numCourses; ++i){
            auto& mm = m[i];
        }

        for(auto&& it : prerequisites){
            m[it[0]].first.emplace_back(it[1]);
            m[it[1]].second++;
        }

        for(const auto& it: m){
            if(it.second.second == 0){
                if(!DFS(it.first)){
                    return {};
                }
            }
        }

        if(s.size() != numCourses) return {};

        return s;
    }

private:
    std::unordered_map<int, std::pair<std::vector<int>, int>> m;
    std::unordered_set<int> circleDetect;
    std::unordered_set<int> sRecord;
    std::vector<int> s;

    bool DFS(int num){
        if(m.find(num) == m.end()){
            s.emplace_back(num);
            sRecord.insert(num);
            return true;
        }

        for(const auto& it : m[num].first){
            if(circleDetect.find(it) != circleDetect.end()){
                return false;
            }
            if(sRecord.find(it) != sRecord.end()){
                continue;
            }
            circleDetect.insert(it);
            if(!DFS(it)){
                return false;
            }
            circleDetect.erase(it);
        }
        s.emplace_back(num);
        sRecord.insert(num);
        return true;
    }
};
// @lc code=end

