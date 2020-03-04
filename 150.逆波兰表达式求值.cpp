/*
 * @lc app=leetcode.cn id=150 lang=cpp
 *
 * [150] 逆波兰表达式求值
 */

// @lc code=start
#include <vector>
#include <string>

class Solution {
public:
    int evalRPN(std::vector<std::string>& tokens) {
        std::vector<long> v;
        for(const auto& it : tokens){
            if(it == "+"){
                v[v.size() - 2] += v[v.size() - 1];
            }else if(it == "-"){
                v[v.size() - 2] -= v[v.size() - 1];
            }else if(it == "*"){
                v[v.size() - 2] *= v[v.size() - 1];
            }else if(it == "/"){
                v[v.size() - 2] /= v[v.size() - 1];
            }else{
                v.emplace_back(std::stoll(it));
                continue;
            }
            v.erase(v.end()-1);
        }
        return v.back();
    }
};
// @lc code=end

