/*
 * @lc app=leetcode.cn id=216 lang=cpp
 *
 * [216] 组合总和 III
 */

// @lc code=start
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> combinationSum3(int k, int n) {
        this->k = k;
        this->n = n;
        DFS({}, 0);
        return result;
    }

private:
    std::vector<std::vector<int>> result;
    int k, n;
    void DFS(std::vector<int>&& r, int sum){
        if(r.size() == k && sum == n){
            result.emplace_back(r);
        }

        for(int i = (r.empty()?1:r.back() + 1); i <= 9; ++i){
            r.emplace_back(i);
            DFS(std::move(r), sum + i);
            r.pop_back();
        }
    }

};
// @lc code=end

