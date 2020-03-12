/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
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
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr) return nullptr;
        ListNode* preHead = nullptr;
        ListNode* afterHead = head->next;
        while(afterHead != nullptr){
            if(preHead == nullptr){
                preHead = head;
                preHead->next = nullptr;
            }
            else{
                preHead = head;
            }
            head = afterHead;
            afterHead = afterHead->next;
            head->next = preHead;
        }
        return head;
    }
};
// @lc code=end

