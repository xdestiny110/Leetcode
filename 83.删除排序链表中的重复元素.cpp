/*
 * @lc app=leetcode.cn id=83 lang=cpp
 *
 * [83] 删除排序链表中的重复元素
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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr)
            return nullptr;
        auto ret = head;
        auto headPre = head;
        head = head->next;
        while(head != nullptr){
            if(head->val == headPre->val)
                headPre->next = head->next;
            else
                headPre = head;
            head = head->next;
        }
        return ret;
    }
};
// @lc code=end

