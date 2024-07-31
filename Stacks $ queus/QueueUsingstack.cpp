class MyQueue {
public:
    stack<int> s1;
    stack<int> s2;
    
    MyQueue() {
        
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        if (s1.empty() && s2.empty()) {
            return -1;
        }
        if (!s2.empty()) {
            int top = s2.top();
            s2.pop();
            return top;
        } else {
            while (!s1.empty()) {
                auto top = s1.top();
                s1.pop();
                s2.push(top);
            }
        }
        int top = s2.top();
        s2.pop();
        return top;
    }
    
    int peek() {
        if (s1.empty() && s2.empty()) {
            return -1;
        }
        if (!s2.empty()) {
            return s2.top();
        } else {
            while (!s1.empty()) {
                auto top = s1.top();
                s1.pop();
                s2.push(top);
            }
        }
        return s2.top();
    }
    
    bool empty() {
        return s1.empty() && s2.empty();
    }
};