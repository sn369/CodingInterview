class Solution {
   public:
    // 入队 = 压入 stack1
    void push(int node) { stack1.push(node); }

    int pop() {
        // stack2 为空时，将 stack1 中的元素依次压入
        if (stack2.empty()) {
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        // stack2 不会空时，栈顶即为队列首元素
        int value = stack2.top();
        stack2.pop();
        return value;
    }

   private:
    stack<int> stack1;
    stack<int> stack2;
};