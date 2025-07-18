class MyQueue
{
private:
    stack<int> t1;
    stack<int> t2;

public:
    MyQueue()
    {
    }

    void push(int x)
    {

        while (!t1.empty())
        {
            t2.push(t1.top());
            t1.pop();
        }
        t1.push(x);

        while (!t2.empty())
        {
            t1.push(t2.top());
            t2.pop();
        }
    }

    int pop()
    {
        int ele = t1.top();
        t1.pop();
        return ele;
    }

    int peek()
    {
        int ele = t1.top();

        return ele;
    }

    bool empty()
    {
        return t1.empty();
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