#include<iostream>
#include<vector>
#include <queue>
using namespace std;

class Node {
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

Node* buildTree(vector<int>& arr, int& index) {
    if (index >= arr.size() || arr[index] == -1) {
        index++;
        return NULL;
    }

    Node* root = new Node(arr[index]);
    index++;
    
    root->left = buildTree(arr, index);
    root->right = buildTree(arr, index);
    
    return root;
}

void levelOrderTraversal(Node* root) {
    if (root == NULL) return;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* current = q.front();
        q.pop();
        cout << current->data << " ";
        
        if (current->left != NULL) {
            q.push(current->left);
        }
        if (current->right != NULL) {
            q.push(current->right);
        }
    }
}

int main() {
    vector<int> arr = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    int index = 0;
    
    Node* root = buildTree(arr, index);
    
    cout << "Level Order Traversal: ";
    levelOrderTraversal(root);
    cout << endl;

    return 0;
}