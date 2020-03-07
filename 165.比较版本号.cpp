/*
 * @lc app=leetcode.cn id=165 lang=cpp
 *
 * [165] 比较版本号
 */

// @lc code=start
#include <string>
#include <regex>

class Solution {
public:
    int compareVersion(std::string version1, std::string version2) {
        std::regex r(R"(\d+)");
        std::smatch m1, m2;
        std::string result = "";
        auto flag1 = std::regex_search(version1, m1, r);
        auto flag2 = std::regex_search(version2, m2, r);
        while(flag1 || flag2)
        {
            long v1 = 0, v2 = 0;
            if(flag1){
                v1 = std::stol(m1.str());
                version1 = m1.suffix();
                flag1 = std::regex_search(version1, m1, r);
            }
            if(flag2){
                v2 = std::stol(m2.str());
                version2 = m2.suffix();
                flag2 = std::regex_search(version2, m2, r);
            }
            if(v1 > v2) return 1;
            if(v1 < v2) return -1;
        }
        return 0;
    }
};
// @lc code=end

