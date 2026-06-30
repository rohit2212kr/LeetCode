class MinStack {
    stack<int> st1;
    stack<int> st2;
public:
    MinStack() {
        
    }
    
    void push(int value) {
        st1.push(value);
        if(st2.empty()){
            st2.push(value);
        }
        else{
            if(value<st2.top()){
                st2.push(value);
            }
            else{
                st2.push(st2.top());
            }
        }
    }
    
    void pop() {
        st2.pop();
        st1.pop();
    }
    
    int top() {
       return st1.top();
    }
    
    int getMin() {
        int a = st2.top();
        return a;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */