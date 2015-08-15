#include <iostream>
#include <stack>

using namespace std;

class Queue {
public:
    // Push element x to the back of queue.
    void push(int x) {
        while(!que.empty()){
          tmq.push(que.top());
          que.pop();
        }
        que.push(x);
        while(!tmq.empty()){
          que.push(tmq.top());
          tmq.pop();
        }
    }

    // Removes the element from in front of queue.
    void pop(void) {
        que.pop();
    }

    // Get the front element.
    int peek(void) {
        return que.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return que.empty();
    }
private:
    stack<int> que, tmq;
};
