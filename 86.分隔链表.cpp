/*
 * @lc app=leetcode.cn id=86 lang=cpp
 *
 * [86] 分隔链表
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
    ListNode* partition(ListNode* head, int x) {
        ListNode* left = nullptr;
        ListNode* right = nullptr;
        ListNode* leftHead = nullptr;
        ListNode* rightHead = nullptr;

        while(head != nullptr){
            if(head->val < x){
                if(left == nullptr){
                    left = head;
                    leftHead = head;
                }
                else{
                    left->next = head;
                    left = head;
                }
            }
            else{
                if(right == nullptr){
                    right = head;
                    rightHead = head;
                }
                else{
                    right->next = head;
                    right = head;
                }
            }
            head = head->next;
        }
        if(left != nullptr)
            left->next = rightHead;
        if(right != nullptr)
            right->next = nullptr;
        return (left == nullptr)?rightHead:leftHead;
    }
};
// @lc code=end

