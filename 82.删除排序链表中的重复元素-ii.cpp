/*
 * @lc app=leetcode.cn id=82 lang=cpp
 *
 * [82] 删除排序链表中的重复元素 II
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
        
        ListNode* ret = nullptr;
        ListNode* retNew = nullptr;
        while(head != nullptr){
            bool dup;
            auto n = findDifferentNode(head, dup);
            if(dup){
                auto t = new ListNode(head->val);
                if(ret == nullptr){
                    ret = t;
                    retNew = t;
                }
                else{
                    retNew->next = t;
                    retNew = t;
                }
            }
            head = n;
        }
        return ret;
    }
private:
    ListNode* findDifferentNode(ListNode* head, bool& dup) const{
        auto val = head->val;
        head = head->next;
        dup = ((head == nullptr) || (val != head->val))?true:false;
        while((head != nullptr) && (head->val == val)){
            head = head->next;
        }
        return head;
    }
};
// @lc code=end

