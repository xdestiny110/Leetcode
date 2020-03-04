/*
 * @lc app=leetcode.cn id=143 lang=cpp
 *
 * [143] 重排链表
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

#include <vector>

class Solution {
public:
    void reorderList(ListNode* head) {
        if(head == nullptr) return;

        std::vector<ListNode*> v;
        auto* h = head;
        while(h != nullptr){
            v.emplace_back(h);
            h = h->next;
        }

        auto it = v.begin();
        auto jt = v.end() - 1;
        bool flag = true;
        while(it != jt){
            if(flag){
                (*it)->next = *jt;
                ++it;    
            }
            else{
                (*jt)->next = *it;
                --jt;
            }
            flag ^= true;
        }
        (*it)->next = nullptr;
    }
};
// @lc code=end

