/*
Design a stack that supports push, pop, top, and retrieving the minimum 
element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
 

Example:

MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> Returns -3.
minStack.pop();
minStack.top();      --> Returns 0.
minStack.getMin();   --> Returns -2.
 
*/

//solution
class MinStack {
    stack<int> sta;
    stack<int> msta;
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }

    void push(int x) {
        if(sta.size() == 0){
            sta.push(x);
            msta.push(x);
        }else{
            int top = msta.top();
            if(x < top)
                msta.push(x);
            else
                msta.push(msta.top());
            sta.push(x);
        }
    }
    
    void pop() {
        if(sta.size() == 0)
            return;
        
        sta.pop();
        msta.pop();
    }
    
    int top() {
        return sta.top();
    }
    
    int getMin() {
        return msta.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */