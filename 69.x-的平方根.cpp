/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根
 */
class Solution {
public:
    int mySqrt(int x) {
        if(x < 2)
            return x;
        return binarySearch(0, x, x);
    }

private:
    int binarySearch(int bound1, int bound2, const int& target){
        unsigned long long t = (bound1+bound2)/2;
        unsigned long long curMul = t*t;
        if(curMul == target || t == bound1)
            return t;
        if(curMul < target){
            return binarySearch(t, bound2, target);
        }
        return binarySearch(bound1, t, target);
    }

};

