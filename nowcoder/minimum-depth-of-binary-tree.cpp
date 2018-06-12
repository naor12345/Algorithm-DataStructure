// 求一棵树的最矮高度，从根节点到最近到一颗叶节点路径上节点个数。

class Solution {
public:
    using tree = TreeNode;
    int run(TreeNode *root) {
        return helper(root);
    }
    
    int helper(tree *root)
    {
        if(root == NULL)
        {
            return 0;
        }
        int a = INT_MAX;
        int b = INT_MAX;
        if(root->left != NULL)
        {
            a = helper(root->left);
        }
        if(root->right != NULL)
        {
            b = helper(root->right);
        }
        if(a == INT_MAX && b == INT_MAX)
        {
            return 1;
        }
        
        return min(a, b) + 1;        
    }
};