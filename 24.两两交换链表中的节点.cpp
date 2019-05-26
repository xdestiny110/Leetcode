/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
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
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
            return head;
        auto* cur = head;
        auto* next = head->next;
        cur->next = next->next;
        next->next = cur;
        head = next;
        auto* prev = cur;
        cur = cur->next;
        if(cur != nullptr)
            next = cur->next;
        while(cur != nullptr && next != nullptr){
            cur->next = next->next;
            next->next = cur;
            prev->next = next;
            prev = cur;
            cur = cur->next;
            if(cur != nullptr)
                next = cur->next;
        }
        return head;
    }
};

