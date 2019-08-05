/*
 * @lc app=leetcode.cn id=43 lang=cpp
 *
 * [43] 字符串相乘
 */

#include <vector>
#include <string>
#include <utility>

class Solution {
public:
    std::string multiply(std::string num1, std::string num2) {
        if((num1 == "") || (num2 == ""))
            return "";
        if((num1 == "0") || (num2 == "0"))
            return "0";
        
        std::vector<char> prod(num1.size()+num2.size(), 0);
        for(int i = num1.size()-1; i>= 0; i--){
            for(int j = num2.size()-1; j >= 0; j--){
                auto idx = num1.size()-i-1+num2.size()-j-1;
                prod[idx] += (num1[i]-'0')*(num2[j]-'0');
                for(int k = idx; k < prod.size(); k++){
                    if(prod[k] >= 10){
                        prod[k+1] += prod[k] / 10;
                        prod[k] = prod[k] % 10;
                    }
                    else
                        break;
                }
            }
        }

        std::string ret;
        bool flag = false;
        for(int i = prod.size()-1; i >= 0; i--){
            if(!flag && prod[i] == 0)
                continue;
            flag = true;
            ret.append(1, prod[i] + '0');
        }

        return flag?ret:"0";
    }
};

