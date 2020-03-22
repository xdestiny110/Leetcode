/*
 * @lc app=leetcode.cn id=225 lang=cpp
 *
 * [225] 用队列实现栈
 */

// @lc code=start
#include <stack>

class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {

    }
    
    /** Push element x onto stack. */
    void push(int x) {
        s.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        auto r = s.top();
        s.pop();
        return r;
    }
    
    /** Get the top element. */
    int top() {
        return s.top();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return s.empty();
    }
private:
    std::stack<int> s;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end

