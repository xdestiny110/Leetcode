/*
 * @lc app=leetcode.cn id=122 lang=rust
 *
 * [122] 买卖股票的最佳时机 II
 */

// @lc code=start
impl Solution {
    pub fn max_profit(prices: Vec<i32>) -> i32 {
        let mut prices_stack = vec![];
        let mut result = 0;
        for price in prices {
            match prices_stack.len() {
                0 => { prices_stack.push(price); },
                1 => {
                    if price > prices_stack[0] {
                        prices_stack.push(price);
                    } else {
                        prices_stack[0] = price;
                    }
                },
                2 => {
                    if price > prices_stack[1] {
                        prices_stack[1] = price;
                    } else {
                        result += prices_stack[1] - prices_stack[0];
                        prices_stack.pop();
                        prices_stack[0] = price;
                    }
                },
                _ => {}
            }
        }
        if prices_stack.len() == 2 {
            result += prices_stack[1] - prices_stack[0];
        }
        return result;
    }
}
// @lc code=end

