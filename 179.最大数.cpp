/*
 * @lc app=leetcode.cn id=179 lang=cpp
 *
 * [179] 最大数
 */

// @lc code=start

#include <string>
#include <vector>
#include <set>
#include <algorithm>

class IntString{
public:
    IntString(int _val): val(std::to_string(_val)){}

    bool operator < (const IntString& other) const {
        for(int i = 0; i < std::min(val.size(), other.val.size()); ++i){
            if(val[i] != other.val[i]){
                return val[i] > other.val[i];
            }
        }
        if(val.size() < other.val.size()){
            for(int i = val.size(); i < other.val.size(); ++i){
                for(int j = 0; j < val.size(); ++j){
                    if(val[j] != other.val[i]){
                        return val[j] > other.val[i];
                    }
                }
            }
        }
        else{
            for(int i = other.val.size(); i < val.size(); ++i){
                for(int j = 0; j < other.val.size(); ++j){
                    if(val[i] != other.val[j]){
                        return val[i] > other.val[j];
                    }
                }
            }
        }
        
        return false;
    }
    std::string val;
};

class Solution {
public:
    std::string largestNumber(std::vector<int>& nums) {
        std::multiset<IntString> s;
        for(const auto& it : nums){
            s.insert(IntString(it));
        }

        std::string r = "";
        for(const auto& it : s){
            if((r != "0") || (it.val != "0"))
                r += it.val;
        }
        return r;
    }
};
// @lc code=end

