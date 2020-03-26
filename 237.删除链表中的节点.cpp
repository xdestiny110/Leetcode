/*
 * @lc app=leetcode.cn id=237 lang=cpp
 *
 * [237] 删除链表中的节点
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
    void deleteNode(ListNode* node) {
        if(node == nullptr) return;
        auto* n = node;
        while(n->next != nullptr){
            n->val = n->next->val;
            if(n->next->next == nullptr){
                n->next = nullptr;
                break;
            }
            else{
                n = n->next;
            }
        }
    }
};
// @lc code=end

