/*
 * @lc app=leetcode.cn id=203 lang=cpp
 *
 * [203] 移除链表元素
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
    ListNode* removeElements(ListNode* head, int val) {
        auto* ret = head;
        ListNode* preHead = nullptr;
        while(head != nullptr){
            if(head->val == val){
                if(preHead == nullptr){
                    head = head->next;
                    ret = head;
                }
                else{
                    preHead->next = head->next;
                    head = head->next;
                }
            }
            else{
                preHead = head;
                head = head->next;
            }
        }
        return ret;
    }
};
// @lc code=end

