// 155.最小栈
//
// 设计一个支持 push ，pop ，top 操作，并能在常数时间内检索到最小元素的栈。
// 实现 MinStack 类:
// * MinStack() 初始化堆栈对象。
// * void push(int value) 将元素 value 推入堆栈。
// * void pop() 删除堆栈顶部的元素。
// * int top() 获取堆栈顶部的元素。
// * int getMin() 获取堆栈中的最小元素。

class MinStack {
public:
    stack<int> vec;
    stack<int> min_stk;
    MinStack() {
        min_stk.push(INT_MAX);
    }
    
    void push(int value) {
       vec.push(value); 
       min_stk.push(min(min_stk.top(), value));
    }
    
    void pop() {
        vec.pop();
        min_stk.pop();
    }
    
    int top() {
        return vec.top(); 
    }
    
    int getMin() {
        return min_stk.top();
    }
};

