/*
 * @lc app=leetcode.cn id=2739 lang=cpp
 *
 * [2739] 总行驶距离
 */

// @lc code=start
class Solution {
public:
    int distanceTraveled(int mainTank, int additionalTank) {
        int distance = 0;
        int costTank = 0;
        while (mainTank > 0) {
            distance += 10;
            mainTank--;
            costTank++;
            if (costTank == 5) {
                if (additionalTank > 0) {
                    additionalTank--;
                    mainTank++;
                }
                costTank = 0;
            }
        }
        return distance;
    }
};
// @lc code=end

