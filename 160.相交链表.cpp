/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int aLenght = 0;
        auto* ha = headA;
        while(ha != nullptr && ha->next != nullptr){
            ha = ha->next;
            aLenght++;
        }
        
        auto* hb = headB;
        int bLength = 0;
        while(hb != nullptr && hb->next != nullptr){
            hb = hb->next;
            bLength++;
        }

        if(ha != hb) return nullptr;
        if(aLenght > bLength){
            for(int i = 0; i < aLenght - bLength; i++){
                headA = headA->next;
            }
        }
        else{
            for(int i = 0; i < bLength - aLenght; i++){
                headB = headB->next;
            }
        }
        while(headB != headA){
            headA = headA->next;
            headB = headB->next;
        }
        return headA;
    }
};
// @lc code=end

