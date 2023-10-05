/*
 * @lc app=leetcode.cn id=121 lang=rust
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
impl Solution {
    pub fn max_profit(prices: Vec<i32>) -> i32 {
        let mut min_price = Option::<i32>::None;
        let mut result = 0;
        for price in prices {
            if let Some(min_price) = min_price.as_mut() {
                result = result.max(price - *min_price);
                *min_price = (*min_price).min(price);
            } else {
                min_price = Some(price);
            }
        }
        result
    }
}
// @lc code=end

