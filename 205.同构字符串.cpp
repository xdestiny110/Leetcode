/*
 * @lc app=leetcode.cn id=205 lang=cpp
 *
 * [205] 同构字符串
 */

// @lc code=start
#include <string>
#include <unordered_map>

class Solution {
public:
    bool isIsomorphic(std::string s, std::string t) {
        change(std::move(s));
        change(std::move(t));
        return s == t;
    }

private:
    void change(std::string&& s){
        char c = 1;
        std::unordered_map<char, char> m;
        for(auto&& it : s){
            auto jt = m.find(it);
            if(jt != m.end()){
                it = jt->second;
            }
            else{
                m[it] = c;
                it = c++;
            }
        }
    }
};
// @lc code=end

