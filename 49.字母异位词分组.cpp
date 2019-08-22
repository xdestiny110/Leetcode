/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */

#include <vector>
#include <string>
#include <unordered_map>

class Solution {
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
        std::unordered_map<std::string, int> records;
        std::vector<std::vector<std::string>> result;
        for(const auto& it : strs){
            std::string key(26, '0');
            for(const auto& jt : it)
                key[jt-'a'] += 1;
            if(records.find(key) == records.end()){
                records[key] = result.size();
                result.emplace_back(std::vector<std::string>());
            }
            result[records[key]].push_back(it);
        }
        return result;
    }
};

