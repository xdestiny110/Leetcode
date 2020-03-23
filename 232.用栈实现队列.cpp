/*
 * @lc app=leetcode.cn id=232 lang=cpp
 *
 * [232] 用栈实现队列
 */

// @lc code=start
#include <stack>

class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {

    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        sIn.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        fillOutStack();
        auto r = sOut.top();
        sOut.pop();
        return r;
    }
    
    /** Get the front element. */
    int peek() {
        fillOutStack();
        return sOut.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return sIn.empty() && sOut.empty();
    }

private:
    std::stack<int> sIn, sOut;

    void fillOutStack(){
        if(sOut.empty()){
            while(!sIn.empty()){
                sOut.push(sIn.top());
                sIn.pop();
            }
        }
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end

