/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第N个节点
 */
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        auto* first = head;
        for(int i = 0;i < n; i++)
            first = first->next;
        auto* second = head;
        auto* third = head;
        while(first != nullptr){
            first = first->next;
            third = second;
            second = second->next;
        }
        if(third == second){
            third = second->next;
            delete second;
            return third;
        }
        third->next = second->next;
        delete second;
        return head;
    }
};

