/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {

public:
 int maxSum;

 int solve(TreeNode* root){
    if(root == NULL) return 0;
    int l = solve(root->left);
    int r = solve(root->right);

    int n = l + r + root->val;
    int k = max(l,r) + root->val;
    int o = root->val;

    maxSum = max({maxSum, n, k, o});
    return max(k,o);
 }

    int maxPathSum(TreeNode* root) {
        maxSum = INT_MIN;
        solve(root);

        return maxSum;
        
    }
};
