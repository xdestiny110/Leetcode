/*
 * @lc app=leetcode.cn id=901 lang=cpp
 *
 * [901] 股票价格跨度
 */

// @lc code=start

#include <stack>
#include <unordered_map>

class StockSpanner {
public:
    StockSpanner() {

    }
    
    int next(int price) {
        int pop_cnt = 0;
        while (!price_index.empty() && price >= price_index.top().first) {
            pop_cnt += price_index.top().second;
            price_index.pop();
        }
        price_index.push({price, pop_cnt + 1});
        return price_index.top().second;
    }

private:
    std::stack<std::pair<int, int>> price_index;
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
// @lc code=end

