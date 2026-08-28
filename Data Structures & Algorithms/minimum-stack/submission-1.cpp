class MinStack {
public:
    stack<int> s;
    stack<int> sMin;
    MinStack() {
        
    }
    
    void push(int val) {
        s.push(val);
        if(sMin.empty()){
            sMin.push(val);
        }else{
            sMin.push(min(sMin.top(), val));
        }
    }
    
    void pop() {
        s.pop();
        sMin.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return sMin.top();
    }
};
