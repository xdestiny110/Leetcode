/*
 * @lc app=leetcode.cn id=71 lang=cpp
 *
 * [71] 简化路径
 */

#include <string>
#include <vector>

class Solution {
public:
    std::string simplifyPath(std::string path) {

        std::vector<std::string> layer;
        bool flag = false;
        std::string tmp = "";
        for(const auto& it : path){
            if(it == '/'){
                if(tmp != ""){
                    if(tmp == ".."){
                        if(!layer.empty())
                            layer.erase(layer.end()-1);
                    }
                    else if(tmp != "."){
                        layer.emplace_back(std::move(tmp));
                    }
                    tmp = "";
                }
            }
            else{
                tmp.append(1, it);
            }
        }
        if(tmp != ""){
            if(tmp == ".."){
                if(!layer.empty())
                    layer.erase(layer.end()-1);
            }
            else if(tmp != "."){
                layer.emplace_back(std::move(tmp));
            }
            tmp = "";
        }
        
        for(const auto& it : layer){
            tmp += "/";
            tmp += it;
        }
        return (tmp == "")?"/":tmp;
    }
};

