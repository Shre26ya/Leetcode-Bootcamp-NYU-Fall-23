class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return valid(root, LONG_MIN, LONG_MAX);
    }
    
private:
    bool valid(TreeNode* root, long left, long right) {
        if (root == NULL) return true;
        
        if (root->val <= left || root->val >= right) return false;
        
        return valid(root->left, left, root->val) && valid(root->right, root->val, right);
    }
};
:
