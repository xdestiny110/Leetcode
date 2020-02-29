/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 */

// @lc code=start

#include <vector>
#include <string>

class Solution {
public:
    std::vector<std::vector<std::string>> partition(std::string s) {
        return DFS(s, s.begin(), s.end());
    }

private:
    std::vector<std::vector<std::string>> DFS(const std::string& s, std::string::const_iterator start, std::string::const_iterator end){
        if(end - start == 1){
            return {{std::string(1, *start)}};
        }

        std::vector<std::vector<std::string>> result;
        if(check(start, end)){
            result.emplace_back().emplace_back(std::string(start, end));
        }
        for(auto i = start + 1; i < end; ++i){
            if(check(start, i)){
                auto c2 = DFS(s, i, end);
                combine(std::move(result), {{std::string(start, i)}}, c2);
            }
        }
        return result;
    }

    void combine(std::vector<std::vector<std::string>>&& r, const std::vector<std::vector<std::string>>& c1, const std::vector<std::vector<std::string>>& c2) const{
        r.reserve(r.size() + c1.size() * c2.size());
        for(const auto& it : c1){
            for(const auto& jt : c2){
                r.emplace_back(it);
                r.back().insert(r.back().end(), jt.begin(), jt.end());
            }
        }
    }

    bool check(std::string::const_iterator it, std::string::const_iterator jt) const {
        jt--;
        while(it < jt){
            if(*it == *jt){
                it++;
                jt--;
            }
            else{
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

