/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵
 */

#include <vector>

class Solution {
public:
    bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty())
            return false;
        int r = 0;
        if(target > matrix.back().back())
            return false;
        for(; r < matrix.size(); r++){
            if(target < matrix[r][0])
                return false;
            if(target > matrix[r].back())
                continue;
            break;
        }
        return binarySearch(matrix[r], target, 0, matrix[0].size()-1);
    }

private:
    bool binarySearch(const std::vector<int>& arr, int target, int lBound, int rBound){
        int mid = (lBound+rBound)/2;
        if(arr[mid] == target || arr[rBound] == target)
            return true;
        if(mid == lBound && arr[rBound] != target)
            return false;

        if(arr[mid] > target)
            return binarySearch(arr, target, lBound, mid);
        return binarySearch(arr, target, mid, rBound);
    }
};

