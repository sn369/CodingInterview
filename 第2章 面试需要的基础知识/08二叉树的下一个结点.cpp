class Solution {
   public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode) {
        if (pNode == NULL) return NULL;
        // 如果有右子树
        if (pNode->right) {
            // 下一个结点就是右子树的最左子节点
            pNode = pNode->right;
            while (pNode->left) {
                pNode = pNode->left;
            }
            return pNode;
        } else {  // 否则，沿着指向父节点的指针一直向上遍历
            // 直到找到一个是它父节点的左子节点的结点
            while (pNode->next && pNode->next->left != pNode) {
                pNode = pNode->next;
            }
            // 该结点的父节点就是下一个结点
            return pNode->next;
        }
        return NULL;
    }
};