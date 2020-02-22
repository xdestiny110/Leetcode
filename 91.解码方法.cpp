/*
 * @lc app=leetcode.cn id=91 lang=cpp
 *
 * [91] 解码方法
 */

#include <string>

// @lc code=start
class Solution {
public:
    int numDecodings(std::string s) {
        DFS(0, s);
        return ret;
    }
private:
    void DFS(int idx, const std::string& s){
        if(idx >= s.size()){
            ret++;
            return;
        }
        if(s[idx] != '0'){
            DFS(idx + 1, s);
        }
        else
        {
            return;
        }
        
        if(idx + 1 < s.size() && (s[idx] - '0') * 10 + s[idx + 1] - '0' <= 26){
            DFS(idx + 2, s);
        }
    }
    int ret = 0;
};
// @lc code=end

