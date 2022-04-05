class MyQueue {
public:
    stack<int>finalQ,temp;
    MyQueue() {
        
    }
    
    void push(int x) {
        while(!finalQ.empty()){
            temp.push(finalQ.top());
            finalQ.pop();
        }
        finalQ.push(x);
        while(!temp.empty()){
            finalQ.push(temp.top());
            temp.pop();
        }
    }
    
    int pop() {
        int x = finalQ.top();
        finalQ.pop();
       return x;
    }
    
    int peek() {
       return finalQ.top();
    }
    
    bool empty() {
       if(finalQ.empty()){
           return true;
       }
        return false;
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