class Queue {
public:
    // Push element x to the back of queue.
    void push(int x) {
        tran(st2,st1);
        st1.push(x);
        tran(st1,st2);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        st2.pop();
    }

    // Get the front element.
    int peek(void) {
        return st2.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return st2.empty();
    }
private:
    stack<int> st1,st2;
    void tran(stack<int> &st1,stack<int> &st2)
    {
        while(!st1.empty())
        {
            st2.push(st1.top());
            st1.pop();
        }
    }
};