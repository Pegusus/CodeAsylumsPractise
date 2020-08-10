Problem Link - https://leetcode.com/problems/implement-stack-using-queues/



class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {

    }
    queue<int> q1;
    /** Push element x onto stack. */
   void push(int x) {
    q1.push(x);
}

/** Removes the element on top of the stack and returns that element. */
int pop() {
    int len = q1.size();
    for(int i = 0; i < len - 1; i++) {
        int tmp = q1.front();
        q1.pop();
        q1.push(tmp);
    }
    int res = q1.front();
    q1.pop();

    return res;
}

/** Get the top element. */
int top() {
    return q1.back();
}

/** Returns whether the stack is empty. */
bool empty() {
    return q1.empty();
}
};





Problem Link - https://leetcode.com/problems/implement-queue-using-stacks/submissions/


class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {

    }
    stack<int> s1,s2;
    /** Push element x to the back of queue. */
    void push(int x) {
        s1.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int len = s1.size();
        for(int i = 0;i<len-1;i++){
            s2.push(s1.top());
            s1.pop();
        }
        int res = s1.top();
        s1.pop();
         for(int i = 0;i<s2.size();i++){
            s1.push(s2.top());
            s2.pop();
        }
        return res;
    }

    /** Get the front element. */
    int peek() {
         int len = s1.size();
        for(int i = 0;i<len;i++){
            s2.push(s1.top());
            s1.pop();
        }
        int res = s2.top();
         for(int i = 0;i<s2.size();i++){
            s1.push(s2.top());
            s2.pop();
        }
        return res;
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return s1.empty();
    }
};
