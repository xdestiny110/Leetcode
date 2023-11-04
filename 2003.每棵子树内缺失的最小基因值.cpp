/*
 * @lc app=leetcode.cn id=2003 lang=cpp
 *
 * [2003] 每棵子树内缺失的最小基因值
 */

// @lc code=start
class Solution {
public:
    vector<int> smallestMissingValueSubtree(vector<int>& parents, vector<int>& nums) {
        int n=parents.size();
        vector<int> ans(n);
        vector<int> appear(n+1,0);
        vector<vector<int>> g(n);
        vector<vector<int>> v(n,vector<int>(2,-1));
        vector<int> son(n,-1);
        for(int i=0;i<n;i++){
            if(parents[i]!=-1){
                g[i].push_back(parents[i]);
                g[parents[i]].push_back(i);
            }
        }
        g[0].push_back(-1);
        for(int i=0;i<n;i++) if(nums[i]<=n) appear[nums[i]]=1;
        int k=n+1;
        for(int i=n;i>0;i--) if(!appear[i]) k=i;
        function<int(int,int)> dfs1=[&](int x,int fa){
            if(g[x].size()==1){
                v[x][0]=nums[x];
                return nums[x];
            }
            for(auto y:g[x]){
                if(y==fa) continue;
                int t=dfs1(y,x);
                if(v[x][0]==-1||t<v[x][0]){
                    v[x][1]=v[x][0];
                    v[x][0]=t;
                    son[x]=y;
                }else if(v[x][1]==-1||t<v[x][1]) v[x][1]=t;
            }
            return min(v[x][0],nums[x]);
        };
        dfs1(0,-1);
        function<void(int,int,int)> dfs2=[&](int x,int fa,int last){
            ans[x]=last;
            if(g[x].size()==1) return;
            for(auto y:g[x]){
                if(y==fa) continue;
                if(son[x]==y){
                    if(v[x][1]==-1) dfs2(y,x,min(last,nums[x]));
                    else dfs2(y,x,min({last,nums[x],v[x][1]}));
                }else dfs2(y,x,min({last,nums[x],v[x][0]}));
            }
        };
        dfs2(0,-1,k);
        return ans;
    }
};
// @lc code=end

