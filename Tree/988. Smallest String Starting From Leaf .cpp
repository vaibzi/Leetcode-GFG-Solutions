//MEdium
//TC- O(N), SC -> O(H)

// You are given the root of a binary tree where each node has a value in the range [0, 25] representing the letters 'a' to 'z'.

// Return the lexicographically smallest string that starts at a leaf of this tree and ends at the root.
// As a reminder, any shorter prefix of a string is lexicographically smaller.

// For example, "ab" is lexicographically smaller than "aba".
class Solution {
public:
    string smallestFromLeaf(TreeNode* root) {
        string ans;
        dfs(root, "", ans);
        return ans;
    }
    
    void dfs(TreeNode* root, string path, string& ans) {
        if (!root) return;
        
        path += char('a' + root->val);
        
        if (!root->left && !root->right) {
            reverse(path.begin(), path.end());
            if (ans.empty() || path < ans) {
                ans = path;
            }
            reverse(path.begin(), path.end());
        }
        
        dfs(root->left, path, ans);
        dfs(root->right, path, ans);
    }
};
