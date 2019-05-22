/*
 * @lc app=leetcode.cn id=12 lang=cpp
 *
 * [12] 整数转罗马数字
 */
class Solution {
public:
    string intToRoman(int num) {
        std::unordered_map<int, std::string> m = {
            {1, "I"},
            {2, "II"},
            {3, "III"},
            {4, "IV"},
            {5, "V"},
            {6, "VI"},
            {7, "VII"},
            {8, "VIII"},
            {9, "IX"},
        }; 
        std::unordered_map<int, char> mi = {
            {0, 'I'},
            {1, 'X'},
            {2, 'C'},
            {3, 'M'}
        };
        std::unordered_map<int, char> mv = {
            {0, 'V'},
            {1, 'L'},
            {2, 'D'} 
        };

        int cnt = 0;
        std::vector<std::string> v(4, "");
        while(num > 0){
            int t = num % 10;
            num /= 10;
            v[cnt] = m[t];
            std::transform(v[cnt].begin(), v[cnt].end(), v[cnt].begin(), [&](char c){
                switch (c)
                {
                case 'X':
                   return mi[cnt+1];
                case 'I':
                    return mi[cnt];
                default:
                    return mv[cnt];
                }   
            });
            cnt++;
        }
        return v[3]+v[2]+v[1]+v[0];
    }
};

