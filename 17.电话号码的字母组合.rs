/*
 * @lc app=leetcode.cn id=17 lang=rust
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start

use std::collections::HashMap;

fn dfs(digits: &str, digit_map: &HashMap<char, &str>, result: &mut String, results: &mut Vec<String>) {
    if digits.len() == 0 {
        results.push((*result).clone());
        return;
    }
    let digit = digits.chars().nth(0).unwrap();
    for c in digit_map[&digit].chars() {
        result.push(c);
        dfs(&digits[1..], digit_map, result, results);
        result.pop();
    }
}

impl Solution {
    pub fn letter_combinations(digits: String) -> Vec<String> {
        if digits.is_empty() {
            return Vec::new();
        }

        let mut digit_map = HashMap::new();
        digit_map.insert('2', "abc");
        digit_map.insert('3', "def");
        digit_map.insert('4', "ghi");
        digit_map.insert('5', "jkl");
        digit_map.insert('6', "mno");
        digit_map.insert('7', "pqrs");
        digit_map.insert('8', "tuv");
        digit_map.insert('9', "wxyz");

        let mut results = Vec::new();
        let mut result = String::new();
        dfs(&digits, &digit_map, &mut result, &mut results);
        return results;
    }
}
// @lc code=end

