/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr && l2 == nullptr)
            return nullptr;

        ListNode* ret = new ListNode(0);
        ListNode* lastNode = nullptr;
        auto* root = ret;
        while(l1 != nullptr && l2 != nullptr){
            ret->val += l1->val + l2->val;
            ret->next = new ListNode(0);
            ret->next->val += ret->val / 10;
            ret->val -= ret->val / 10 * 10;
            lastNode = ret;
            ret = ret->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1 != nullptr){
            ret->val += l1->val;
            ret->next = new ListNode(0);
            ret->next->val += ret->val / 10;
            ret->val -= ret->val / 10 * 10;
            lastNode = ret;
            ret = ret->next;
            l1 = l1->next;
        }
        while(l2 != nullptr){
            ret->val += l2->val;
            ret->next = new ListNode(0);
            ret->next->val += ret->val / 10;
            ret->val -= ret->val / 10 * 10;
            lastNode = ret;
            ret = ret->next;
            l2 = l2->next;
        }
        if(ret->val == 0){
            delete ret;
            ret = lastNode;
            lastNode->next = nullptr;
        }
        return root;
    }
};

