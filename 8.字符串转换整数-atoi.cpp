/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */
class Solution {
public:
    int myAtoi(string str) {
        int noSpace = -1;
        for(int i = 0;i < str.size(); i++){
            if(str[i] != ' '){
                noSpace = i;
                break;
            }
        }
        if(noSpace < 0)
            return 0;
        if(str[noSpace] != '-' && str[noSpace] != '+' && (str[noSpace] > '9' || str[noSpace] < '0'))
            return 0;
        std::string numSign = "";
        if(str[noSpace] == '-' || str[noSpace] == '+'){
            if(str[noSpace] == '-')
                numSign = "-";
            noSpace++;
        }
        int validEnd = str.size();
        for(int i = noSpace; i < str.size();i++){
            if(str[i] > '9' || str[i] < '0'){
                validEnd = i;
                break;
            }
        }

        std::string ret(str, noSpace, validEnd-noSpace);
        if(ret.size() <= 0)
            return 0;
        if(ret.size() > 1){
            int noZero = -1;
            for(int i = 0; i < ret.size(); i++){
                if(ret[i] != '0'){
                    noZero = i;
                    break;
                }
            }
            if(noZero < 0)
                return 0;
            ret = ret.substr(noZero);
        }
        std::string maxStr = std::to_string(std::numeric_limits<int>::max());
        std::string minStr = std::to_string(std::numeric_limits<int>::min());
        ret = numSign + ret;
        if(numSign.size() > 0){
            if(ret.size() > minStr.size())
                return std::numeric_limits<int>::min();
            if(ret.size() == minStr.size()){
                for(int i = 0;i < minStr.size(); i++){
                    if(ret[i] > minStr[i])
                        return std::numeric_limits<int>::min();
                    else if(ret[i] < minStr[i])
                        break;
                }
            }
        }
        else{
            if(ret.size() > maxStr.size())
                return std::numeric_limits<int>::max();
            if(ret.size() == maxStr.size()){
                for(int i = 0;i < maxStr.size(); i++){
                    if(ret[i] > maxStr[i])
                        return std::numeric_limits<int>::max();
                    else if(ret[i] < maxStr[i])
                        break;
                }
            }
        }
        return std::stoi(ret);
    }
};

