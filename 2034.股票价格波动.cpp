/*
 * @lc app=leetcode.cn id=2034 lang=cpp
 *
 * [2034] 股票价格波动
 */

// @lc code=start

#include <map>
#include <unordered_map>
#include <unordered_set>
#include <optional>

class StockPrice {
public:
    StockPrice() {

    }
    
    void update(int timestamp, int price) {
        if (auto it = time_price_.find(timestamp); it != time_price_.end()) {
            price_times_[it->second].erase(timestamp);
            if (price_times_[it->second].empty()) {
                price_times_.erase(it->second);
            }
        }
        time_price_.insert_or_assign(timestamp, price);
        price_times_[price].insert(timestamp);

        if (!newest_.has_value() || timestamp >= newest_->first) {
            newest_ = {timestamp, price};
        }
    }
    
    int current() const {
        return newest_->second;
    }
    
    int maximum() const {
        return price_times_.rbegin()->first;
    }
    
    int minimum() const {
        return price_times_.begin()->first;
    }

private:
    std::unordered_map<int, int> time_price_;
    std::map<int, std::unordered_set<int>> price_times_;
    std::optional<std::pair<int, int>> newest_ = std::nullopt;
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */
// @lc code=end

