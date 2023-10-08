/*
 * @lc app=leetcode.cn id=901 lang=rust
 *
 * [901] 股票价格跨度
 */

// @lc code=start
struct StockSpanner {
    // price/count
    stack: Vec::<(i32, i32)>,
}


/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl StockSpanner {

    fn new() -> Self {
        StockSpanner { stack: vec![] }
    }
    
    fn next(&mut self, price: i32) -> i32 {
        let mut current = (price, 1);
        while !self.stack.is_empty() && self.stack[self.stack.len() - 1].0 <= current.0 {
            current.1 += self.stack[self.stack.len() - 1].1;
            self.stack.pop();
        }
        self.stack.push(current);
        current.1
    }
}

/**
 * Your StockSpanner object will be instantiated and called as such:
 * let obj = StockSpanner::new();
 * let ret_1: i32 = obj.next(price);
 */
// @lc code=end

