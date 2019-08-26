/*
 * @lc app=leetcode.cn id=61 lang=cpp
 *
 * [61] 旋转链表
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr || head->next == nullptr)
            return head;
        auto* ptr = head;
        ListNode* tail = nullptr;
        int len = 0;
        while(ptr != nullptr){
            len++;
            if(ptr->next == nullptr)
                tail = ptr;
            ptr = ptr->next;
        }

        k %= len;
        if(k == 0)
            return head;
        ptr = head;
        for(int i = 0; i < len-k-1; i++){
            ptr = ptr->next;
        }
        if(ptr == nullptr){
            return head;
        }

        auto* ptrNext = ptr->next;
        tail->next = head;
        ptr->next = nullptr;
        return ptrNext;
    }
};

