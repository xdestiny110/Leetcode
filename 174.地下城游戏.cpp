/*
 * @lc app=leetcode.cn id=174 lang=cpp
 *
 * [174] 地下城游戏
 */

// @lc code=start
#include <algorithm>
#include <vector>

class Solution {
public:
    int calculateMinimumHP(std::vector<std::vector<int>>& dungeon) {
        std::vector<std::vector<int>> beforeEntryLife(dungeon.size());
        for(auto&& it : beforeEntryLife){
            it.resize(dungeon[0].size());
        }

        beforeEntryLife.back().back() = (dungeon.back().back() >= 0)?1 : 1 - dungeon.back().back();

        for(int r = dungeon.size() - 2; r >= 0; --r){
            beforeEntryLife[r][dungeon[0].size() - 1] = std::max(1, beforeEntryLife[r+1][dungeon[0].size() - 1] - dungeon[r][dungeon[0].size() - 1]);
        }
        for(int c = dungeon[0].size() - 2; c >= 0; --c){
            beforeEntryLife[dungeon.size() - 1][c] = std::max(1, beforeEntryLife[dungeon.size() - 1][c+1] - dungeon[dungeon.size() - 1][c]);
        }

        for(int r = dungeon.size() - 2; r >= 0; --r){
            for(int c = dungeon[0].size() - 2; c >= 0; --c){
                beforeEntryLife[r][c] = std::max(1, std::min(beforeEntryLife[r+1][c] - dungeon[r][c], beforeEntryLife[r][c+1] - dungeon[r][c]));
            }
        }
        return beforeEntryLife[0][0];
    }
};
// @lc code=end

