/*
 * @lc app=leetcode.cn id=1654 lang=cpp
 *
 * [1654] 到家的最少跳跃次数
 */

// @lc code=start
#include <vector>
#include <queue>
#include <unordered_set>

struct JumpNode {
    int depth = 0;
    int pos = 0;
    int back_step = 0;
};

class Solution {
public:
    int minimumJumps(std::vector<int>& forbidden, int a, int b, int x) {
        if (x == 0) return 0;
        std::unordered_set<int> forbidden_set;
        for (auto f : forbidden) {
            forbidden_set.insert(f);
        }

        int right_border = (a >= b) ? x + b : *std::max_element(forbidden_set.begin(), forbidden_set.end()) + a + b + x;

        std::queue<JumpNode> s;
        s.push({});
        while (!s.empty()) {
            auto& n = s.front();
            if (n.pos + a <= right_border && n.pos + a > 0 && forbidden_set.find(n.pos + a) == forbidden_set.end()) {
                if (n.pos + a == x) {
                    return n.depth + 1;
                }
                s.push(JumpNode{
                    .depth = n.depth + 1,
                    .pos = n.pos + a,
                    .back_step = 0,
                });
                forbidden_set.insert(n.pos + a);
            }
            if (n.pos - b > 0 && n.back_step < 1 && forbidden_set.find(n.pos - b) == forbidden_set.end()) {
                if (n.pos - b == x) {
                    return n.depth + 1;
                }
                s.push(JumpNode{
                    .depth = n.depth + 1,
                    .pos = n.pos - b,
                    .back_step = n.back_step + 1,
                });
            }
            s.pop();
        }
        return -1;
    }
};
// @lc code=end

