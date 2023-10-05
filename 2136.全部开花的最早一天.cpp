/*
 * @lc app=leetcode.cn id=2136 lang=cpp
 *
 * [2136] 全部开花的最早一天
 */

// @lc code=start
struct Bag{
    int p,g;
    friend bool operator <(Bag a,Bag b)
    {
        return a.g>b.g;
    }
};
 
class Solution {
public:
    Bag bag[100010];
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int n=plantTime.size();
        for(int i=0;i<n;i++)
        {
            bag[i].p=plantTime[i];
            bag[i].g=growTime[i];
        }
        sort(bag,bag+n);
        int ret=0;
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=bag[i].p;
            ret=max(ret,sum+bag[i].g);
        }
        return ret;
    }
};
// @lc code=end

