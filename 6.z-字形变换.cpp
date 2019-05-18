/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] Z 字形变换
 */
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1)
            return s;
        std::vector<std::vector<char>> zippo(numRows);
        int r = 0;
        bool flag = true;
        for(auto& it : s){
            zippo[r].push_back(it);
            if(flag){
                r++;
                if(r >= numRows){
                    flag = false;
                    r-=2;
                }
            }
            else{
                r--;
                if(r < 0){
                    flag = true;
                    r+=2;
                }
            }
        }
        std::string ret = "";
        for(auto& it : zippo){
            for(auto& jt : it){
                ret += std::string(1, jt);
            }
        }
        return ret;
    }
};

