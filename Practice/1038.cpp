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
    int sum = 0;

    void solve(TreeNode* root, int &sum){
        if(root == NULL) return;

        solve(root->right, sum);

        sum += root->val;

        root->val = sum;

        solve(root->left, sum);




    }

    TreeNode* bstToGst(TreeNode* root) {

        solve(root, sum);
        return root;
        
    }
};
