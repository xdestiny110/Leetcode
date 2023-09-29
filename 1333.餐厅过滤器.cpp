/*
 * @lc app=leetcode.cn id=1333 lang=cpp
 *
 * [1333] 餐厅过滤器
 */

// @lc code=start

#include <vector>
#include <set>

struct Restaurant {
    int id_;
    int rating_;
};

bool operator<(const Restaurant& lhs, const Restaurant& rhs) {
    return (lhs.rating_ < rhs.rating_) || (lhs.rating_ == rhs.rating_ && lhs.id_ < rhs.id_);
}

class Solution {
public:
    std::vector<int> filterRestaurants(std::vector<std::vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        std::set<Restaurant> restaurants_after_filter;
        for (const auto& r : restaurants) {
            if ((!veganFriendly || r[2]) && r[3] <= maxPrice && r[4] <= maxDistance) {
                restaurants_after_filter.insert(Restaurant{
                    .id_ = r[0],
                    .rating_ = r[1],
                });
            }
        }

        std::vector<int> result;
        result.reserve(restaurants_after_filter.size());
        for (auto it = restaurants_after_filter.rbegin(); it != restaurants_after_filter.rend(); ++it) {
            result.push_back(it->id_);
        }
        return result;
    }
};
// @lc code=end

