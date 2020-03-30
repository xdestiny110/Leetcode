/*
 * @lc app=leetcode.cn id=241 lang=cpp
 *
 * [241] 为运算表达式设计优先级
 */

// @lc code=start
#include <stack>
#include <vector>
#include <string>
#include <string_view>

class Solution {
public:
    std::vector<int> diffWaysToCompute(std::string input) {
        std::string_view sv(input.c_str());
        return DFS(sv);
    }

private:

    int stoi(std::string_view str) const {
        int ret = 0;
        int plus = 1;
        for(auto it = str.rbegin(); it != str.rend(); ++it){
            ret += (*it-'0') * plus;
            plus *= 10;
        }
        return ret;
    }

    std::vector<int> DFS(std::string_view str) const {
        std::vector<int> ret;
        for(int i = 0; i < str.size(); ++i){
            if(str[i] == '+' || str[i] == '-' || str[i] == '*'){
                auto r1 = DFS(str.substr(0, i));
                auto r2 = DFS(str.substr(i+1));
                for(const auto& it : r1){
                    for(const auto& jt : r2){
                        switch (str[i])
                        {
                        case '+':
                            ret.emplace_back(it+jt);
                            break;
                        case '-':
                            ret.emplace_back(it-jt);
                            break;
                        case '*':
                            ret.emplace_back(it*jt);
                            break;
                        default:
                            break;
                        }
                    }
                }
            }
        }
        if(ret.empty()){
            ret.emplace_back(stoi(str));
        }
        return ret;
    }


};
// @lc code=end

