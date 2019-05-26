/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 实现strStr()
 */
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle == "")
            return 0;
        for(int i = 0;i < (int)haystack.size()-(int)needle.size()+1; i++){
            bool flag = true;
            for(int j = 0;j < needle.size();j++){
                if(needle[j] != haystack[i+j]){
                    flag = false;
                    break;
                }
            }
            if(flag)
                return i;
        }
        return -1;
    }
};

