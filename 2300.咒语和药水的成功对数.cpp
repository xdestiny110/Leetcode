/*
 * @lc app=leetcode.cn id=2300 lang=cpp
 *
 * [2300] 咒语和药水的成功对数
 */

// @lc code=start

#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<int> successfulPairs(std::vector<int>& spells, std::vector<int>& potions, long 
    long success) {
        std::sort(potions.begin(), potions.end());
        std::vector<int> result(spells.size());
        for (int i = 0; i < spells.size(); ++i) {
            int idx = binary_search(spells[i], potions, success);
            result[i] = (idx == -1) ? 0 : potions.size() - idx;
        }
        return result;        
    }

private:
    int binary_search(int64_t spell, const std::vector<int>& potions, long long success) {
        int head = 0;
        int tail = potions.size() - 1;
        while (head < tail - 1) {
            auto mid = (head + tail) / 2;
            if (spell * potions[mid] >= success) {
                tail = mid;
            } else {
                head = mid;
            }
        }
        if (spell * potions[tail] < success) return -1;
        return spell * potions[head] < success ? tail : head;
    }
};
// @lc code=end

