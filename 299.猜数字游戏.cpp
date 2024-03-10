/*
 * @lc app=leetcode.cn id=299 lang=cpp
 *
 * [299] 猜数字游戏
 */

// @lc code=start

#include <vector>
#include <string>
#include <unordered_set>

class Solution {
public:
    std::string getHint(std::string secret, std::string guess) {
        std::string result;
        int bull_cnt = 0;
        std::unordered_multiset<char> remain_secret;
        std::vector<char> remain_guess;
        for (int i = 0; i <secret.size(); ++i) {
            if (secret[i] == guess[i]) {
                bull_cnt++;
            } else {
                remain_secret.insert(secret[i]);
                remain_guess.push_back(guess[i]);
            }
        }
        result += std::to_string(bull_cnt) + "A";
        
        int cow_cnt = 0;
        for (auto g : remain_guess) {
            if (auto it = remain_secret.find(g); it != remain_secret.end()) {
                cow_cnt++;
                remain_secret.erase(it);
            }
        }
        result += std::to_string(cow_cnt) + "B";
        return result;
    }
};
// @lc code=end

