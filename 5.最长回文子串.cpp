/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */
class Solution {
public:
    string longestPalindrome(string s) {
        if(s == "")
            return "";
        int maxLength = 1;
        string ret = s.substr(0,1);
        for(int i = 1;i < s.size(); i++){
            int j = 1;
            for(j = 1;;j++){
                if(i-j < 0 || i+j >= s.size() || s[i-j] != s[i+j]){
                    j--;
                    break;
                }
            }
            if(maxLength < 1+2*j){
                maxLength = 1+2*j;
                ret = s.substr(i-j, maxLength);
            }
            maxLength = (maxLength<1+2*j)?1+2*j:maxLength;
            if(s[i] == s[i-1]){
                for(j = 1;;j++){
                    if(i-j-1 < 0 || i+j >= s.size() || s[i-j-1] != s[i+j]){
                        j--;
                        break;
                    }
                }
                if(maxLength < 2+2*j){
                    maxLength = 2+2*j;
                    ret = s.substr(i-j-1, maxLength);
                }
            }
        }
        return ret;
    }
};

