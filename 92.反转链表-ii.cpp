/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        auto* currentNode = head;
        ListNode* currentPreNode = nullptr; 
        int cnt = 1;
        while(currentNode != nullptr && cnt < m){
            cnt++;
            currentPreNode = currentNode;
            currentNode = currentNode->next;
        }
        auto* flipPreNode = currentPreNode;
        auto* flipNode = currentNode;
        currentPreNode = currentNode;
        currentNode = currentNode->next;
        cnt++;
        while(currentNode != nullptr && cnt <= n){
            auto* t1 = currentNode->next;
            currentNode->next = currentPreNode;
            currentPreNode = currentNode;
            currentNode = t1;
            cnt++;
        }
        flipNode->next = currentNode;
        if(m != 1)
        {
            flipPreNode->next = currentPreNode;
            return head;
        }        
        return currentPreNode;
    }
};
// @lc code=end

