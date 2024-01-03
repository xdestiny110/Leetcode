/*
 * @lc app=leetcode.cn id=2660 lang=cpp
 *
 * [2660] 保龄球游戏的获胜者
 */

// @lc code=start
#include <vector>
#include <optional>

class Solution {
public:
    int isWinner(std::vector<int>& player1, std::vector<int>& player2) {
        auto score1 = calc_score(player1);
        auto score2 = calc_score(player2);
        if (score1 == score2) {
            return 0;
        }
        return (score1 > score2) ? 1 : 2;
    }

private:
    int calc_score(const std::vector<int>& scores) {
        std::optional<int> bounds = std::nullopt;
        int player_score = 0;
        for (int i = 0; i < scores.size(); ++i) {
            if (bounds.has_value() && *bounds + 2 >= i) {
                player_score += scores[i] * 2;
            } else {
                player_score += scores[i];
                bounds = std::nullopt;
            }
            if (scores[i] == 10) {
                bounds = i;
            }
        }
        return player_score;
    }
};
// @lc code=end

