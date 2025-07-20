// Min Stack

// Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

// Implement the MinStack class:

// MinStack() initializes the stack object.
// void push(int val) pushes the element val onto the stack.
// void pop() removes the element on the top of the stack.
// int top() gets the top element of the stack.
// int getMin() retrieves the minimum element in the stack.
// You must implement a solution with O(1) time complexity for each function.

// Example 1:

// Input
// ["MinStack","push","push","push","getMin","pop","top","getMin"]
// [[],[-2],[0],[-3],[],[],[],[]]

// Output
// [null,null,null,null,-3,null,0,-2]

// Explanation
// MinStack minStack = new MinStack();
// minStack.push(-2);
// minStack.push(0);
// minStack.push(-3);
// minStack.getMin(); // return -3
// minStack.pop();
// minStack.top();    // return 0
// minStack.getMin(); // return -2

class MinStack
{
private:
    long long min;
    stack<long long> st;

public:
    MinStack() : min(LLONG_MAX) {}

    void push(int val)
    {
        if (st.empty())
        {
            st.push((long long)val);
            min = val;
        }
        else
        {
            if (val >= min)
            {
                st.push((long long)val);
            }
            else
            {

                st.push(2LL * val - min);
                min = val;
            }
        }
    }

    void pop()
    {
        if (st.empty())
            return;

        if (st.top() < min)
        {

            min = 2LL * min - st.top();
        }
        st.pop();
    }

    int top()
    {
        if (st.empty())
            throw runtime_error("Stack is empty");

        if (st.top() < min)
        {

            return (int)min;
        }
        return (int)st.top();
    }

    int getMin()
    {
        if (st.empty())
            throw runtime_error("Stack is empty");
        return (int)min;
    }
};
