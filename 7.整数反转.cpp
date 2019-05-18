/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */
class Solution {
public:
    int reverse(int x) {
        std::string minStr = std::to_string(std::numeric_limits<int>::min());
        std::string maxStr = std::to_string(std::numeric_limits<int>::max());
        std::string str = std::to_string(x);
        if(x < 0){
            std::reverse(str.begin()+1, str.end());
            if(str.size() == minStr.size()){
                for(int i = 1;i < str.size()-1;i++){
                    if(str[i] > minStr[i+minStr.size()-str.size()])
                        return 0;
                    else if(str[i] < minStr[i+minStr.size()-str.size()])
                        break;
                }
            }
        }
        else{
            std::reverse(str.begin(), str.end());
            if(str.size() == maxStr.size()){
                for(int i = 0;i < str.size()-1;i++){
                    if(str[i] > maxStr[i+maxStr.size()-str.size()])
                        return 0;
                    else if(str[i] < maxStr[i+maxStr.size()-str.size()])
                        break;
                }
            }
        }
        return std::stoi(str);
    }
};

