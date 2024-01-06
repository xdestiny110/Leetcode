/*
 * @lc app=leetcode.cn id=2487 lang=cpp
 *
 * [2487] 从链表中移除节点
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

#include <vector>

class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        std::vector<ListNode*> stack;
        auto* h = head;
        while (h != nullptr) {
            while (!stack.empty() && stack.back()->val < h->val) {
                stack.pop_back();
            }
            stack.push_back(h);
            h = h->next;
        }
        for (int i = 1; i < stack.size(); ++i) {
            stack[i - 1]->next = stack[i];
        }
        stack.back()->next = nullptr;
        return stack.front();
    }
};
// @lc code=end

