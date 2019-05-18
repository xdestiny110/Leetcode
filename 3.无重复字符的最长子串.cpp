/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s == "")
            return 0;
        std::vector<int> f(s.size());
        f[0] = 1;
        for(int i = 1;i < s.size();i++){
            int c = -1;
            for(int j = i-1;j >= i-f[i-1];j--){
                if(s[i] == s[j]){
                    c = j;
                    break;
                }
            }
            if(c >= 0)
                f[i] = i-c;
            else
                f[i] = f[i-1]+1;
        }
        return *std::max_element(f.begin(), f.end());
    }
};

