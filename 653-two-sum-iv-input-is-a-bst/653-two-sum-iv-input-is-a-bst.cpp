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
    void solve(TreeNode* root, vector<int> &in){
        if(root == NULL){
            return;
        }
        solve(root ->left, in);
        in.push_back(root ->val);
        solve(root ->right, in);
    }
public:
    bool findTarget(TreeNode* root, int k) {
        vector<int> ans;
        //Storing the inorder of BST
        solve(root, ans);
        //Using two pointer approach
        int i = 0;
        int j = ans.size()-1;
        while(i<j){
            int sum = ans[i]+ans[j];
            if(k == sum){
                return true;
            }
            else if(k<sum){
                j--;
            }else{
                i++;
            }
        }
        return false;
    }
};