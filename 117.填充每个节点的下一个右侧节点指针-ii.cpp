/*
 * @lc app=leetcode.cn id=117 lang=cpp
 *
 * [117] 填充每个节点的下一个右侧节点指针 II
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
class Solution {
public:
    Node* connect(Node* root) {
        auto* n = root;
        Node* nextRoot = nullptr;
        Node* m = nullptr;
        while(n != nullptr){
            if(m != nullptr){
                if(n->left != nullptr){
                    m->next = n->left;
                    m = m->next;
                }
                else if(n->right != nullptr){
                    m->next = n->right;
                    m = m->next;
                }
            }
            if(n->left != nullptr && n->right != nullptr){
                n->left->next = n->right;
                if(m != nullptr) m = n->right;
                nextRoot = (nextRoot == nullptr)?n->left:nextRoot;
            }
            else if(n->right == nullptr && n->left != nullptr){
                nextRoot = (nextRoot == nullptr)?n->left:nextRoot;
            }
            else if(n->left == nullptr && n->right != nullptr){
                nextRoot = (nextRoot == nullptr)?n->right:nextRoot;
            }
            if(m == nullptr){
                if(n->right != nullptr){
                    m = n->right;
                }
                else if(n->left != nullptr){
                    m = n->left;
                }
            }
            n = n->next;
        }
        if(nextRoot != nullptr) connect(nextRoot);
        return root;
    }

};
// @lc code=end

