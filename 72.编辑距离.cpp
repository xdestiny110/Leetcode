/*
 * @lc app=leetcode.cn id=72 lang=cpp
 *
 * [72] 编辑距离
 */

#include <string>
#include <vector>

class Solution {
public:
    int minDistance(std::string word1, std::string word2) {
        if(word1.empty())
            return word2.size();
        if(word2.empty())
            return word1.size();
        std::vector<std::vector<int>> f;
        for(int i = 0; i <= word1.size(); i++)
            f.emplace_back(word2.size()+1);

        for(int i = 0; i <= word1.size(); i++)
            f[i][0] = i;
        for(int j = 0; j <= word2.size(); j++)
            f[0][j] = j;

        for(int i = 1; i <= word1.size(); i++){
            for(int j = 1; j <= word2.size(); j++){
                if(word1[i-1] == word2[j-1])
                    f[i][j] = std::min(std::min(f[i-1][j-1], f[i-1][j]+1), f[i][j-1]+1);
                else
                    f[i][j] = std::min(std::min(f[i-1][j-1]+1, f[i-1][j]+1), f[i][j-1]+1);
            }
        }
        return f.back().back();
    }
};

