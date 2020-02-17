class Solution {
   public:
    TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
        // 从前序序列中获取根节点，然后在中序中找到根节点，左右分别为左右子树
        return construct(pre, 0, pre.size(), vin, 0, vin.size());
    }

    TreeNode* construct(const vector<int>& pre, int preStart, int preEnd,
                        const vector<int>& vin, int vinStart, int vinEnd) {
        // 注意循环结束的条件
        if (preStart >= preEnd || vinStart >= vinEnd) return NULL;
        // 前序遍历序列的第一个数字就是根节点的值
        TreeNode* root = new TreeNode(pre[preStart]);
        for (int i = vinStart; i < vinEnd; i++) {
            // 扫描中序遍历序列，确定根节点的值的位置
            if (vin[i] == pre[preStart]) {
                // 在根节点的值的前面的数字都是左子树节点的值
                root->left = construct(
                    pre, preStart + 1, preStart + 1 + i - vinStart, vin,
                    vinStart, i);  // 注意左子树的结点个数为 i - vinStart
                // 后面的是右子树节点的值
                root->right = construct(pre, preStart + 1 + i - vinStart,
                                        preEnd, vin, i + 1, vinEnd);
                break;
            }
        }
        return root;
    }
};