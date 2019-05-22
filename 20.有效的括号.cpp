/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */
class Solution {
public:
    bool isValid(string s) {
        std::stack<char> r;
        std::unordered_map<char, char> m = {
            {'}', '{'},
            {']', '['},
            {')', '('}
        };
        for(auto& it : s){
            switch(it){
                case '(':
                case '[':
                case '{':
                    r.push(it);
                    break;
                case ')':
                case ']':
                case '}':
                    if(!r.empty() && r.top() == m[it])
                        r.pop();
                    else
                        return false;
                    break;
            }
        }
        return r.empty();
    }
};

