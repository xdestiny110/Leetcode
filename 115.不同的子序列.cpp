/*
 * @lc app=leetcode.cn id=115 lang=cpp
 *
 * [115] 不同的子序列
 */

// @lc code=start

#include <string>
#include <vector>

class Solution {
public:
    int numDistinct(std::string s, std::string t) {
        if(s.empty() || t.empty())
            return 0;
        // int will be overflow
        std::vector<std::vector<long>> f(s.size() + 1);
        for(auto&& it : f){
            it.resize(t.size() + 1, 0);
            it[0] = 1;
        }

        for(int b = 1; b <= t.size(); b++){
            for(int a = b; a <= s.size(); a++){
                f[a][b] = f[a-1][b] + ((s[a-1] == t[b-1])?f[a-1][b-1]:0);
            }
        }
        return f[s.size()][t.size()];
    }
};
// @lc code=end

