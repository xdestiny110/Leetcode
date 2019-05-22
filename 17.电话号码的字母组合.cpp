/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        m = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };
        std:string r = "";
        DFS(0, digits, r);
        return ret;
    }
private:
    std::vector<std::string> ret;
    std::unordered_map<char, std::string> m;
    void DFS(int layer, const string& str, std::string& r){
        if(layer >= str.size()){
            if(r != "")
                ret.push_back(r);
            return;
        }
        for(auto& it : m[str[layer]]){
            DFS(layer+1, str, r.append(1, it));
            r.erase(r.size()-1);
        }
    }
};

