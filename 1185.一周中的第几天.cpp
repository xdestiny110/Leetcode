/*
 * @lc app=leetcode.cn id=1185 lang=cpp
 *
 * [1185] 一周中的第几天
 */

// @lc code=start

#include <chrono>
#include <string>

class Solution {
public:
    std::string dayOfTheWeek(int day, int month, int year) {
        std::chrono::year_month_day ymd{std::chrono::year(year), std::chrono::month(month), std::chrono::day(day)};
        std::chrono::year_month_weekday ymwd{std::chrono::sys_days(ymd)};
        std::array<std::string, 7> enum_to_str = {
            "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday",
        };
        return enum_to_str[ymwd.weekday().c_encoding()];
    }
};
// @lc code=end

