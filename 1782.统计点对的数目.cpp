/*
 * @lc app=leetcode.cn id=1782 lang=cpp
 *
 * [1782] 统计点对的数目
 */

// @lc code=start
class Solution
{
public:
    vector<int> countPairs(int n, vector<vector<int>> &edges, vector<int> &queries)
    {
        vector<int> ans;
        // 建图
        vector<int> d(n);
        map<std::pair<int, int>, int> mp;
        for (auto i : edges)
        {
            int x = i[0] - 1, y = i[1] - 1;
            if (x > y)
                swap(x, y);
            mp[{x, y}]++;
            d[x]++, d[y]++;
        }
        vector<int> temp = d;
        sort(temp.begin(), temp.end());
        for (auto p : queries)
        {
            int sum = 0;
            // 双指针
            int j = n - 1;
            for (int i = 0; i < n; i++)
            {
                while (j >= 0 && temp[i] + temp[j] > p)
                {
                    j--;
                }
                sum += (n - 1) - j;
            }
            // 自己和自己匹配
            for (int i = 0; i < n; i++)
            {
                if (temp[i] + temp[i] > p)
                    sum--;
            }
            // 相邻匹配
            for (auto [xx, yy] : mp)
            {
                int x = xx.first, y = xx.second;
                int t = d[x] + d[y];
                if (t > p && t - yy <= p)
                    sum -= 2;
            }
            sum /= 2;
            ans.push_back(sum);
        }
        return ans;
    }
};
// @lc code=end
