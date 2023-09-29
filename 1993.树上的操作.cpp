/*
 * @lc app=leetcode.cn id=1993 lang=cpp
 *
 * [1993] 树上的操作
 */

// @lc code=start
class LockingTree {
public:
    vector<int> p;
    vector<vector<int>> g;
    vector<int> user;
    int n;

    LockingTree(vector<int>& parent) {
        p = parent;
        int n = p.size();
        user.resize(n, -1);
        g.resize(n);

        for (int i = 1; i < n; i ++ )
            g[p[i]].push_back(i);
    }
    
    bool lock(int k, int u) {
        if (user[k] != -1) return false;
        user[k] = u;
        return true;
    }
    
    bool unlock(int k, int u) {
        if (user[k] != u) return false;
        user[k] = -1;
        return true;
    }
    
    int dfs(int u) {
        int res = 0;
        if (user[u] != -1) {
            user[u] = -1;
            res ++ ;
        }

        for (auto son : g[u])
            res += dfs(son);
        
        return res;
    }

    bool upgrade(int k, int u) {
        if (user[k] != -1) return false;
        for (int i = p[k]; i != -1; i = p[i])
            if (user[i] != -1)
                return false;
        
        int cnt = dfs(k);
        if (cnt) {
            user[k] = u;
            return true;
        }
        return false;
    }
};

/**
 * Your LockingTree object will be instantiated and called as such:
 * LockingTree* obj = new LockingTree(parent);
 * bool param_1 = obj->lock(num,user);
 * bool param_2 = obj->unlock(num,user);
 * bool param_3 = obj->upgrade(num,user);
 */
// @lc code=end

