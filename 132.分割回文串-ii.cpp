/*
 * @lc app=leetcode.cn id=132 lang=cpp
 *
 * [132] 分割回文串 II
 */

// @lc code=start
#include <string>
#include <vector>
#include <unordered_set>

class Solution {
public:
    int minCut(std::string s) {
        std::vector<int> f(s.size());
        std::vector<std::vector<bool>> isPalindrome(f.size());
        for(auto&& it : isPalindrome){
            it.resize(f.size());
        }

        for(int l = 1; l < s.size(); ++l){
            for(int i = 0; i < s.size() - l; ++i){
                if(s[i] == s[i+l])
                    isPalindrome[i][i+l] = (i+1 >= i+l-1) || isPalindrome[i+1][i+l-1];
            }
        }

        for(int i = 0; i < s.size(); ++i){
            f[i] = i;
            // insert ',' before s[j]
            for(int j = 0; j <= i; ++j){
                if(s[i] == s[j] && ((j+1 >= i-1) || isPalindrome[j+1][i-1])){
                    f[i] = std::min(f[i], (j==0)?0:f[j-1]+1);
                }
            }
        }
        return f.back();
    }
};
// @lc code=end

