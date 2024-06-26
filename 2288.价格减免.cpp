/*
 * @lc app=leetcode.cn id=2288 lang=cpp
 *
 * [2288] 价格减免
 */

// @lc code=start

#include <algorithm>
#include <string>
#include <string_view>

class Solution {
public:
    std::string discountPrices(std::string sentence, int discount) {
        std::string_view sentence_sv(sentence);
        std::string result;
        size_t idx = 0;
        size_t pos = sentence_sv.find_first_of(' ', idx);
        while (pos != std::string::npos) {
            if (idx != 0) {
                result.append(1, ' ');
            }
            std::string_view substr_sv = sentence_sv.substr(idx, pos - idx);
            if (check(substr_sv)) {
                result.append(discountSV(substr_sv, discount));
            } else {
                result.append(std::string(substr_sv));
            }
            idx = pos + 1;
            pos = sentence_sv.find_first_of(' ', idx);
        }

        if (!result.empty()) result.append(1, ' ');
        std::string_view substr_sv = sentence_sv.substr(idx);
        if (check(substr_sv)) {
            result.append(discountSV(substr_sv, discount));
        } else {
            result.append(std::string(substr_sv));
        }
        return result;
    }

private:
    bool check(std::string_view sv) const {
        return sv.size() > 1 && sv[0] == '$' && std::all_of(sv.begin() + 1, sv.end(), [](char c) {
            return c >= '0' && c <= '9';
        });
    }

    std::string discountSV(std::string_view sv, int discount) const {
        uint64_t num = std::stoull(sv.substr(1).data());
        num = num * (100 - discount);
        auto num_str = std::to_string(num);
        if (num_str.size() < 3) {
            num_str.insert(0, 3 - num_str.size(), '0');
        }
        num_str.insert(num_str.size() - 2, 1, '.');
        num_str.insert(0, 1 , '$');
        return num_str;
    }
};
// @lc code=end

