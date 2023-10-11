/*
 * @lc app=leetcode.cn id=2512 lang=rust
 *
 * [2512] 奖励最顶尖的 K 名学生
 */

// @lc code=start

use std::collections::HashSet;
use std::collections::BinaryHeap;
use std::cmp::Ordering;

#[derive(PartialEq, Eq)]
struct Student {
    id : i32,
    score: i32,
}

impl Ord for Student {
    fn cmp(&self, other: &Student) -> Ordering {
        self.partial_cmp(other).unwrap()
    }
}

impl PartialOrd for Student {
    fn partial_cmp(&self, other: &Student) -> Option<Ordering> {
        if (self.score < other.score) || (self.score == other.score && self.id > other.id) {
            Some(Ordering::Greater)
        } else if (self.score > other.score) || (self.score == other.score && self.id < other.id) {
            Some(Ordering::Less)
        } else {
            Some(Ordering::Equal)
        }
    }
}

impl Solution {
    pub fn top_students(positive_feedback: Vec<String>, negative_feedback: Vec<String>, report: Vec<String>, student_id: Vec<i32>, k: i32) -> Vec<i32> {
        let mut positive_feedback_set =  HashSet::<&String>::new();
        for feedback in positive_feedback.iter() {
            positive_feedback_set.insert(feedback);
        }
        let mut negative_feedback_set = HashSet::<&String>::new();
        for feedback in negative_feedback.iter() {
            negative_feedback_set.insert(feedback);
        }
    
        let mut students = BinaryHeap::<Student>::new();
        for idx in 0..student_id.len() {
            let reports : Vec<String> = report[idx].split(' ').map(|s| s.to_string()).collect();
            let mut score = 0;
            for r in reports.iter() {
                if positive_feedback_set.contains(r) {
                    score += 3;
                } else if negative_feedback_set.contains(r) {
                    score -= 1;
                }            
            }
            students.push(Student { id: student_id[idx], score });
            while students.len() > k as usize {
                students.pop();
            }
        }
    
        let mut result = vec![];
        while !students.is_empty() {
            result.push(students.pop().unwrap().id);
        }
        result.reverse();
        result
    }
}
// @lc code=end

