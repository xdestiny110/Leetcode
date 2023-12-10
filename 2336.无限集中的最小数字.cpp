/*
 * @lc app=leetcode.cn id=2336 lang=cpp
 *
 * [2336] 无限集中的最小数字
 */

// @lc code=start

#include <set>

class SmallestInfiniteSet {
public:
    SmallestInfiniteSet() {
        for (int i = 1; i <= 1000; ++i) {
            s_.insert(i);
        }
    }
    
    int popSmallest() {
        auto result = *s_.begin();
        s_.erase(s_.begin());
        return result;
    }
    
    void addBack(int num) {
        s_.insert(num);
    }

private:
    std::set<int> s_;
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
// @lc code=end

