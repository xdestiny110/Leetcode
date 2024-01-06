/*
 * @lc app=leetcode.cn id=2807 lang=cpp
 *
 * [2807] 在链表中插入最大公约数
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
class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        auto* prev = head;
        auto* next = head->next;
        while (next != nullptr) {
            auto* n = new ListNode(lcd(prev->val, next->val), next);
            prev->next = n;
            prev = next;
            next = next->next;
        }
        return head;
    }

private:
    int lcd(int a, int b) const {
        for (;;) {
            int m = a % b;
            if (m != 0) {
                a = b;
                b = m;
                continue;
            }
            break;
        }
        return b;
    }
};
// @lc code=end

