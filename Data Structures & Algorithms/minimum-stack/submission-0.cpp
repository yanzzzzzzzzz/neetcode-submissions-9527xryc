class MinStack {
private:
    stack<int> st,minStack;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        if(minStack.empty() || minStack.top() >= val){
            minStack.push(val);
        }
    }
    
    void pop() {
        if(st.top() == minStack.top()){
            minStack.pop();
        }
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};
