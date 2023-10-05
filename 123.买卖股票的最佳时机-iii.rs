/*
 * @lc app=leetcode.cn id=123 lang=rust
 *
 * [123] 买卖股票的最佳时机 III
 */

// @lc code=start
impl Solution {
    pub fn max_profit(prices: Vec<i32>) -> i32 {
        // 天数/是否持股/已交易次数
        let mut profit = vec![vec![vec![0;3];2];prices.len()];
        profit[0][1][0] = -prices[0];
        profit[0][1][1] = -prices[0];
        profit[0][1][2] = -prices[0];
        for idx in 1..prices.len() {
            profit[idx][0][1] = profit[idx - 1][0][1].max(profit[idx - 1][1][0] + prices[idx]);
            profit[idx][0][2] = profit[idx - 1][0][2].max(profit[idx - 1][1][1] + prices[idx]);
            profit[idx][1][0] = profit[idx - 1][1][0].max(profit[idx - 1][0][0] - prices[idx]);
            profit[idx][1][1] = profit[idx - 1][1][1].max(profit[idx - 1][0][1] - prices[idx]);
            profit[idx][1][2] = profit[idx - 1][1][2].max(profit[idx - 1][0][2] - prices[idx]);
        }
        profit[prices.len() - 1][0][2]
    }    
}
// @lc code=end

