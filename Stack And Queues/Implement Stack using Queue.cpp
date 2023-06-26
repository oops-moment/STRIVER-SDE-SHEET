class MyStack {
public:
    // so we are gonna use two queue over here to implement the same 
    queue<int>q1;
    queue<int>q2;
    MyStack() {
        
    }
    
    void push(int x) {
        q2.push(x);
        while(!q1.empty())
        {
            int element=q1.front();
            q1.pop();
            q2.push(element);
        }
        swap(q1,q2);
    }
    
    int pop() {
        int ans;
        if(q1.empty())
        {
            ans=-1;

        }
        else
        {
            ans=q1.front();
            q1.pop();
        }
        return ans;
    }
    
    int top() {
        int ans;
        if(q1.empty())
        {
            ans=-1;

        }
        else
        {
            ans=q1.front();
        }
        return ans;
    }
    
    bool empty() {
        if(q1.empty())
        {
            return 1;
        }
        return 0;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
