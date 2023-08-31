/*
 * @lc app=leetcode.cn id=1761 lang=cpp
 *
 * [1761] 一个图中连通三元组的最小度数
 */

// @lc code=start
class Solution {
public:
    int minTrioDegree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n + 1, vector<int>(n + 1, 0));
        vector<int> degree(n + 1, 0);
        for (auto& edge : edges) {
            graph[edge[0]][edge[1]] = 1;
            graph[edge[1]][edge[0]] = 1;
            degree[edge[0]]++;
            degree[edge[1]]++;
        }
        int ans = INT_MAX;
        for (int i = 1; i <= n; i++) {
            if (degree[i] < 2) continue;
            for (int j = i + 1; j <= n; j++) {
                if (degree[j] < 2 || graph[i][j] == 0) continue;
                for (int k = j + 1; k <= n; k++) {
                    if (degree[k] < 2 || graph[i][k] == 0 || graph[j][k] == 0) continue;
                    ans = min(ans, degree[i] + degree[j] + degree[k] - 6);
                }
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
// @lc code=end

