//使用队列实现栈，队列FIFO，栈LIFO
//用两个队列，入栈就直接入队列，出栈需要使用另一个栈把这个移动到另一个栈中，
//然后把两个栈交换一下，就可以了。
class Stack {
private:
  std::queue<int> qstack, tmpq;
public:
    // Push element x onto stack.
    void push(int x) {
        qstack.push(x);
    }

    // Removes the element on top of the stack.
    void pop() {
        int len = qstack.size();
        for(int i = 0; i < len-1; ++i){
          tmpq.push(qstack.front());
          qstack.pop();
        }
        qstack.pop();
        swap(qstack, tmpq);
    }

    // Get the top element.
    int top() {
        return qstack.back();
    }

    // Return whether the stack is empty.
    bool empty() {
        return qstack.empty();
    }
};
