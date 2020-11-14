/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class CBTInserter {
public:
    CBTInserter(TreeNode* root) {
        nodes.push_back(root);
        for(int i = 0; i < nodes.size(); ++i){
            if(nodes[i]->left != nullptr) nodes.push_back(nodes[i]->left);
            if(nodes[i]->right != nullptr) nodes.push_back(nodes[i]->right);
        }
        for(int i = 0; i < nodes.size(); ++i){
            if(nodes[i]->left == nullptr || nodes[i]->right == nullptr){
                currentIdx = i;
                break;
            }
        }
    }
    
    int insert(int v) {
        auto node = new TreeNode(v);
        if(nodes[currentIdx]->left == nullptr){
            nodes[currentIdx]->left = node;
        }
        else if(nodes[currentIdx]->right == nullptr){
            nodes[currentIdx]->right = node;
        }
        else{
            currentIdx++;
            nodes[currentIdx]->left = node;
        }
        nodes.push_back(node);
        return nodes[currentIdx]->val;
    }
    
    TreeNode* get_root() {
        return nodes.front();
    }
private:

    std::vector<TreeNode*> nodes;
    int currentIdx = 0;
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(v);
 * TreeNode* param_2 = obj->get_root();
 */