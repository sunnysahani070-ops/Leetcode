class MinStack {
public:
    stack<long long> st;
    long long mini;

    MinStack() {
    }

    void push(int val) {
        if (st.empty()) {
            st.push(val);
            mini = val;
        }
        else if (val >= mini) {
            st.push(val);
        }
        else {
            st.push(2LL * val - mini);
            mini = val;
        }
    }

    void pop() {
        if (st.empty()) return;

        if (st.top() < mini) {
            mini = 2 * mini - st.top();
        }

        st.pop();
    }

    int top() {
        if (st.top() >= mini)
            return st.top();
        return mini;
    }

    int getMin() {
        return mini;
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