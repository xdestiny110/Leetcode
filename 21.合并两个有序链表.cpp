/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* ret = nullptr;
        ListNode* head = nullptr;
        while(l1 != nullptr && l2 != nullptr){
            ListNode* t = nullptr; 
            if(l1->val < l2->val){
                t = new ListNode(l1->val);
                l1 = l1->next;
            }
            else{
                t = new ListNode(l2->val);
                l2 = l2->next;
            }
            if(ret == nullptr){
                ret = t;
                head = ret;
            }
            else{
                ret->next = t;
                ret = t;
            }
        }
        while(l1 != nullptr){
            if(ret == nullptr){
                ret = new ListNode(l1->val);
                head = ret;
            }
            else{
                ret->next = new ListNode(l1->val);
                ret = ret->next;
            }
            l1 = l1->next;
        }
        while(l2 != nullptr){
            if(ret == nullptr){
                ret = new ListNode(l2->val);
                head = ret;
            }
            else{
                ret->next = new ListNode(l2->val);
                ret = ret->next;
            }
            l2 = l2->next;
        }
        return head;
    }
};

