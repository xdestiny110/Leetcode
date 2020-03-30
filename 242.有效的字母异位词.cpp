/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */

// @lc code=start
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;

        std::vector<int> recordS(26);
        for(const auto& it : s){
            recordS[it - 'a'] += 1;
        }

        std::vector<int> recordT(26);
        for(const auto& it : t){
            recordT[it - 'a'] += 1;
        }

        for(int i = 0; i < 26; ++i){
            if(recordT[i] != recordS[i]) return false;
        }

        return true;
    }
};
// @lc code=end

