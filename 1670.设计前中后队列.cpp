/*
 * @lc app=leetcode.cn id=1670 lang=cpp
 *
 * [1670] 设计前中后队列
 */

// @lc code=start

#include <list>

class FrontMiddleBackQueue {
public:
    FrontMiddleBackQueue() : middle_iter_(mem_.begin()) {

    }
    
    void pushFront(int val) {
        mem_.emplace_front(val);
        if (mem_.size() == 1) {
            middle_iter_ = mem_.begin();
        } else if (mem_.size() % 2) {
            middle_iter_--;
        }
    }
    
    void pushMiddle(int val) {
        if (mem_.empty()) {
            mem_.push_back(val);
            middle_iter_ = mem_.begin();
        } else {
            mem_.insert(middle_iter_, val);
            if (mem_.size() % 2) {
                middle_iter_--;
            }
        }
    }
    
    void pushBack(int val) {
        mem_.emplace_back(val);
        if (mem_.size() == 1) {
            middle_iter_ = mem_.begin();
        } else if (mem_.size() % 2 == 0) {
            middle_iter_++;
        }
    }
    
    int popFront() {
        if (mem_.empty()) return -1;
        auto ret = mem_.front();
        mem_.pop_front();
        if (!mem_.empty() && mem_.size() % 2 == 0) {
            middle_iter_++;
        }
        return ret;
    }
    
    int popMiddle() {
        if (mem_.empty()) return -1;
        if (mem_.size() % 2 == 0) {
            middle_iter_--;   
        }
        auto ret = *middle_iter_;
        middle_iter_ = mem_.erase(middle_iter_);
        return ret;
    }
    
    int popBack() {
        if (mem_.empty()) return -1;
        auto ret = mem_.back();
        if (mem_.size() > 1 && mem_.size() % 2 == 0) {
            middle_iter_--;
        }
        auto it = mem_.end();
        it--;
        mem_.erase(it);
        return ret;
    }

private:
    std::list<int> mem_;
    decltype(mem_)::const_iterator middle_iter_;

};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */
// @lc code=end

