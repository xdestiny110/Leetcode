/*
 * @lc app=leetcode.cn id=1513 lang=cpp
 *
 * [1513] 仅含 1 的子串数
 */

// @lc code=start
class Solution {
public:
    int numSub(string s) {
        unsigned long long lastIdx = -1;
        bool flag = false;
        unsigned long long ret = 0;
        for(unsigned long long i = 0; i < s.size(); ++i){
            if(!flag && s[i] == '1'){
                flag = true;
                lastIdx = i;
            }
            if(flag && s[i] == '0'){
                auto len = i - lastIdx;
                ret += len * (len + 1) / 2;
                flag = false;
            }
        }
        if(flag){
            auto len = static_cast<unsigned long long>(s.size()) - lastIdx;
            ret += len * (len + 1) / 2;
        }
        return ret % (1000000000ull + 7ull);
    }
};
// @lc code=end

