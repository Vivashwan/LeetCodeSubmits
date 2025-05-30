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
    private:
    bool isMirrorOrNot(TreeNode *head1, TreeNode *head2)
    {
        if(head1 == nullptr && head2 == nullptr)
        {
            return true;
        }
        if(head1 == nullptr || head2 == nullptr)
        {
            return false;
        }

        return ((head1->val==head2->val) && isMirrorOrNot(head1->left, head2->right) && isMirrorOrNot(head1->right, head2->left));
    }
public:
    bool isSymmetric(TreeNode* root) {
        if(root==nullptr)return true;
        
        return isMirrorOrNot(root->left, root->right);
    }
};
