/*
 * @lc app=leetcode.cn id=468 lang=cpp
 *
 * [468] 验证IP地址
 */

// @lc code=start

#include <string>
#include <vector>
#include <unordered_map>

class Solution {
public:
    std::string validIPAddress(std::string queryIP) {
        std::unordered_map<char, std::vector<size_t>> char_collection;
        for (size_t i = 0; i < queryIP.size(); ++i) {
            auto c = queryIP[i];
            if (c != ':' && c != '.' && !(c >= '0' && c <= '9') && !(c >= 'a' && c <= 'f') && !(c >= 'A' && c <= 'F')) {
                return "Neither";
            }
            char_collection[c].push_back(i);
        }

        if ((char_collection[':'].size() > 0 && char_collection[':'].size() != 7) ||
        (char_collection['.'].size() > 0 && char_collection['.'].size() != 3) ||
        (char_collection['.'].size() > 0 && char_collection[':'].size() > 0)) {
            return "Neither";
        }

        if (char_collection[':'].size() == 7) {
            for (size_t i = 0; i < char_collection[':'].size(); ++i) {
                if (i == 0) {
                    if (char_collection[':'][i] < 1 || char_collection[':'][i] > 4) {
                        return "Neither";
                    }
                } else {
                    auto num_size = char_collection[':'][i] - char_collection[':'][i - 1] - 1;
                    if (num_size < 1 || num_size > 4) {
                        return "Neither";
                    }
                }
            }
            auto last_size = queryIP.size() - char_collection[':'].back() - 1;
            if (last_size < 1 || last_size > 4) {
                return "Neither";
            }
            return "IPv6";
        }

        if (char_collection['.'].size() == 3) {
            for (size_t i = 0; i < char_collection['.'].size(); ++i) {
                if (i == 0) {
                    if (char_collection['.'][0] < 1 || char_collection['.'][0] > 3) {
                        return "Neither";
                    }
                    bool check_pre_zero = char_collection['.'][0] > 1;
                    for (size_t j = 0; j < char_collection['.'][0]; ++j) {
                        if (!(queryIP[j] >= '0' && queryIP[j] <= '9')) {
                            return "Neither";
                        }
                        if (check_pre_zero && queryIP[j] == '0') {
                            return "Neither";
                        }
                        check_pre_zero = false;
                    }
                    auto num_str = std::stoi(queryIP.substr(0, char_collection['.'][0]));
                    if (num_str > 255) {
                        return "Neither";
                    }
                } else {
                    auto num_size = char_collection['.'][i] - char_collection['.'][i - 1] - 1;
                    if (num_size > 3 || num_size < 1)
                        return "Neither";
                    bool check_pre_zero = num_size > 1;
                    for (size_t j = char_collection['.'][i - 1] + 1; j < char_collection['.'][i]; ++j) {
                        if (!(queryIP[j] >= '0' && queryIP[j] <= '9')) {
                            return "Neither";
                        }
                        if (check_pre_zero && queryIP[j] == '0') {
                            return "Neither";
                        }
                        check_pre_zero = false;
                    }
                    auto num_str = std::stoi(queryIP.substr(char_collection['.'][i - 1] + 1, num_size));
                    if (num_str > 255) {
                        return "Neither";
                    }
                }
            }
            auto last_num_size = queryIP.size() - char_collection['.'].back() - 1;
            if (last_num_size > 3 || last_num_size < 1)
                return "Neither";
            bool check_pre_zero = last_num_size > 1;
            for (size_t j = char_collection['.'].back() + 1; j < queryIP.size(); ++j) {
                if (!(queryIP[j] >= '0' && queryIP[j] <= '9')) {
                    return "Neither";
                }
                if (check_pre_zero && queryIP[j] == '0') {
                    return "Neither";
                }
                check_pre_zero = false;
            }
            auto num_str = std::stoi(queryIP.substr(char_collection['.'].back() + 1));
            if (num_str > 255) {
                return "Neither";
            }
            
            return "IPv4";
        }
        return "Neither";
    }
};
// @lc code=end

