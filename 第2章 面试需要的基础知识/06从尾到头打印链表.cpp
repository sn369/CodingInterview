class Solution {
   public:
    vector<int> ans;
    vector<int> printListFromTailToHead(ListNode* head) {
        // 递归
        if (head) {
            printListFromTailToHead(head->next);
            ans.push_back(head->val);
        }
        return ans;
    }
};

class Solution {
   public:
    vector<int> printListFromTailToHead(ListNode* head) {
        // 用栈存储
        stack<int> stk;
        for (ListNode* p = head; p != NULL; p = p->next) {
            stk.push(p->val);
        }
        vector<int> ans;
        while (!stk.empty()) {
            ans.push_back(stk.top());
            stk.pop();
        }
        return ans;
    }
};