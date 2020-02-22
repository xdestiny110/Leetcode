/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原IP地址
 */
#include <vector>
#include <string>
#include <algorithm>

// @lc code=start
class Solution {
public:
    std::vector<std::string> restoreIpAddresses(std::string s) {
        DFS(0, 0, s, std::string(s));
        return ret;
    }
private:
    std::vector<std::string> ret;
    void DFS(int idx, int layer, const std::string& s, std::string&& r){
        for(int i = idx; i < std::min(idx + 3, static_cast<int>(s.size() - 1)); i++){
            if(i - idx >= 1 && s[idx] == '0')
                return;
            auto ss = s.substr(idx, i - idx + 1);
            if(std::stoi(ss) <= 255){
                r.insert(i + 1 + layer, ".");
                if(layer == 2){
                    auto ssLast = s.substr(i + 1);
                    if(ssLast.size() <= 3 && ssLast.size() > 0 && std::stoi(ssLast) <= 255 && ((ssLast.size() == 1) || (ssLast[0] != '0'))){
                        ret.emplace_back(r);
                    }
                }
                else{
                    DFS(i + 1, layer + 1, s, std::move(r));
                }
                r.erase(i + 1 + layer, 1);
            }
            else
            {
                return;
            }
        }
    }
};
// @lc code=end

