#include<iostream>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Function to calculate the height of a binary tree
int heightOfBinaryTree(TreeNode* root) {
    // Base case: if the node is null, return -1
    if (root == NULL) {
        return -1;
    }
    // Recursive case: calculate the height of left and right subtrees
    int leftHeight = heightOfBinaryTree(root->left);
    int rightHeight = heightOfBinaryTree(root->right);
    // Return the maximum of the two heights plus one for the current node
    return max(leftHeight, rightHeight) + 1;
}

int main() {
    // Create a sample binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    // Calculate the height of the binary tree
    int height = heightOfBinaryTree(root);
    cout << "Height of the binary tree: " << height << endl;

    return 0;
}
