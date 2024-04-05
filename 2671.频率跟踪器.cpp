/*
 * @lc app=leetcode.cn id=2671 lang=cpp
 *
 * [2671] 频率跟踪器
 */

// @lc code=start

#include <unordered_set>
#include <unordered_map>

class FrequencyTracker {
public:
    FrequencyTracker() {

    }
    
    void add(int number) {
        if (auto it = num_cnts.find(number); it != num_cnts.end()) {
            cnt_nums[it->second].erase(it->first);
            it->second++;
            cnt_nums[it->second].insert(it->first);
        } else {
            num_cnts.emplace(number, 1u);
            cnt_nums[1].insert(number);
        }
    }
    
    void deleteOne(int number) {
        if (auto it = num_cnts.find(number); it != num_cnts.end()) {
            cnt_nums[it->second].erase(it->first);
            it->second--;
            if (it->second > 0) {
                cnt_nums[it->second].insert(it->first);   
            } else {
                num_cnts.erase(it);
            }
        }
    }
    
    bool hasFrequency(int frequency) {
        return !cnt_nums[frequency].empty();
    }

private:
    std::unordered_map<size_t, std::unordered_set<int>> cnt_nums;
    std::unordered_map<int, size_t> num_cnts;
};

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker* obj = new FrequencyTracker();
 * obj->add(number);
 * obj->deleteOne(number);
 * bool param_3 = obj->hasFrequency(frequency);
 */
// @lc code=end

