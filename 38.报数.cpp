/*
 * @lc app=leetcode.cn id=38 lang=cpp
 *
 * [38] 报数
 */

#include <string>
#include <vector>

class Solution {
public:
    std::string countAndSay(int n) {
        std::vector<std::string> record(n);
        record[0] = "1";
        for(int i = 1; i < n; i++){
            auto ch = record[i-1][0];
            int cnt = 1;
            std::string r = "";
            for(int j = 1; j < record[i-1].size(); j++){
                if(record[i-1][j] != ch){
                    r += std::to_string(cnt)+std::string(1, ch);
                    cnt = 1;
                    ch = record[i-1][j];
                }
                else{
                    cnt++;
                }
            }
            r += std::to_string(cnt)+std::string(1, ch);
            record[i] = r;
        }
        return record.back();
    }
};

