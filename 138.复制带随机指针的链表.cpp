/*
 * @lc app=leetcode.cn id=138 lang=cpp
 *
 * [138] 复制带随机指针的链表
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr) return nullptr;

        auto* h = head->next;
        auto* result = new Node(head->val);
        auto* r = result;
        while(h != nullptr){
            auto* t = new Node(h->val);
            r->next = t;
            r = t;
            h = h->next;
        }

        h = head;
        r = result;
        while(h != nullptr){
            if(h->random != nullptr){
                auto cnt = distance(head, h->random);
                auto* t = result;
                for(int i = 0; i < cnt; i++){
                    t = t->next;
                }
                r->random = t;
            }
            h = h->next;
            r = r->next;
        }

        return result;
    }
private:
    int distance(Node* head, Node* target) const{
        int result = 0;
        while(head != target){
            result++;
            head = head->next;
        }
        return result;
    }
};
// @lc code=end

