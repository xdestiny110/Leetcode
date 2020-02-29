/*
 * @lc app=leetcode.cn id=133 lang=cpp
 *
 * [133] 克隆图
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node == nullptr) return nullptr;

        std::vector<Node*> oriGraph;
        std::vector<Node*> result;
        oriGraph.emplace_back(node);
        result.emplace_back(new Node(oriGraph[0]->val));

        for(int i = 0; i < oriGraph.size(); ++i){
            for(const auto& it : oriGraph[i]->neighbors){
                auto jt = std::find(oriGraph.begin(), oriGraph.end(), it);
                if(jt != oriGraph.end()){ 
                    result[i]->neighbors.emplace_back(result[std::distance(oriGraph.begin(), jt)]);
                }
                else{
                    oriGraph.emplace_back(it);
                    result.emplace_back(new Node(it->val));
                    result[i]->neighbors.emplace_back(result.back());
                }
            }
        }

        return result[0];
    }


};
// @lc code=end

