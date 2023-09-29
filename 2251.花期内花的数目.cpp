/*
 * @lc app=leetcode.cn id=2251 lang=cpp
 *
 * [2251] 花期内花的数目
 */

// @lc code=start


class Solution {
public:
    map<int, int> a, id;
    int s[150010];
    int cnt = 0;
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& persons) {
        for (auto &x: flowers) a[x[0]] = 1, a[x[1] + 1] = 1;
        for (auto &x: persons) a[x] = 1;
        for (auto &x: a) id[x.first] = ++cnt;
        for (auto &x: flowers) s[id[x[0]]]++, s[id[x[1] + 1]]--;
        for (int i = 1; i <= cnt; i++) s[i] += s[i - 1];
        vector<int> res;
        for (auto &x: persons) res.push_back(s[id[x]]);
        return res;
    }
};
// @lc code=end

