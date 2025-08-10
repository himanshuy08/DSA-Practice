#include <iostream>
#include<vector>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;

        Node(int val) {
            data = val;
            left = NULL;
            right = NULL;
        }
};

Node* buildTree(vector<int>& arr, int& index){
    if(index >= arr.size() || arr[index] == -1) {
        index++;
        return NULL;
    }

    Node* root = new Node(arr[index]);
    index++;
    
    root->left = buildTree(arr, index);
    root->right = buildTree(arr, index);
    
    return root;
}
void preorderTraversal(Node* root){
    if(root==NULL) return ;
    cout<<root->data<<" ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}
void inorderTraversal(Node* root) {
    if(root == NULL) return;
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}
void postorderTraversal(Node* root){
    if(root==NULL) return ;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout<<root->data<<" ";

}
int main() {
    vector<int> arr = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    int index = 0;
    
    Node* root = buildTree(arr, index);
    
    cout<< "Preorder Traversal: ";
    preorderTraversal(root);
    cout<<endl;
    cout<< "Inorder Traversal: ";
    inorderTraversal(root);
    cout << endl;
    cout<< "Postorder Traversal: ";
    postorderTraversal(root);
    cout << endl;
    

    return 0;
}
