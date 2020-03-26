/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <stack>

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        std::stack<int> s;
        auto* h = head;
        while(h != nullptr){
            s.push(h->val);
            h = h->next;
        }

        h = head;
        while(h != nullptr){
            if(h->val != s.top()){
                return false;
            }
            s.pop();
            h = h->next;
        }

        return true;
    }
};
// @lc code=end

