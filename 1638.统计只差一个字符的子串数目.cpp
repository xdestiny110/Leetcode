/*
 * @lc app=leetcode.cn id=1638 lang=cpp
 *
 * [1638] 统计只差一个字符的子串数目
 */

// @lc code=start
#include <string>
#include <algorithm>

class Solution {
public:
    int countSubstrings(std::string s, std::string t) {
        int g[101][101][101];
        memset(g, 0, sizeof(g));

        int ret = 0;
        for(int i = 0; i < s.size(); ++i){
            for(int j = 0; j < t.size(); ++j){
                g[i][j][1] = (s[i] == t[j]) ? 0 : 1;
                if(g[i][j][1] == 1){
                    ret++;
                }
            }
        }

        for(int k = 2; k <= std::min(s.size(), t.size()); ++k){
            for(int i = k - 1; i < s.size(); ++i){
                for(int j = k - 1; j < t.size(); ++j){
                    g[i][j][k] = (s[i] == t[j])?g[i-1][j-1][k-1]:g[i-1][j-1][k-1] + 1;
                    if(g[i][j][k] == 1){
                        ret++;
                    }
                }
            }
        }

        return ret;
    }
};
// @lc code=end

