/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        maxN = n;
        std::string r(n, '(');
        DFS(0, r, 0);
        return results;
    }
private:
    std::vector<std::string> results;
    int maxN = 0;
    void DFS(int layer, std::string r, int lastStart){
        if(layer >= maxN){
            results.push_back(std::move(r));
            return;
        }
        int leftBracketCnt = 0;
        for(int i = 0;i < lastStart; i++)
            leftBracketCnt = (r[i] == '(')?leftBracketCnt+1:leftBracketCnt-1;
        for(int i = lastStart; i <= r.size(); i++){
            if(leftBracketCnt > 0){
                r.insert(i, ")");
                DFS(layer+1, r, i+1);
                r.erase(i, 1);
            }
            leftBracketCnt = (r[i] == '(')?leftBracketCnt+1:leftBracketCnt-1;
        }
    }
};

