#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value){
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

Node* insert(Node* root, int value) {
    if (root == nullptr) {
        return new Node(value);
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    return root;
}
// Function to convert an array to a height-balanced BST
Node* sortedArrayToBST(int arr[], int start, int end) {
    if (start > end) {
        return nullptr;
    }
    int mid = (start + end) / 2;
    Node* root = new Node(arr[mid]);
    root->left = sortedArrayToBST(arr, start, mid - 1);
    root->right = sortedArrayToBST(arr, mid + 1, end);
    return root;
}

void inorderTraversal(Node* root) {
    if (root != nullptr) {
        inorderTraversal(root->left);
        cout << root->data << " ";
        inorderTraversal(root->right);
    }
}

int main() {
    int data[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(data) / sizeof(data[0]);
    Node* root = sortedArrayToBST(data, 0, n - 1);
    cout << "Inorder traversal of the height-balanced BST: ";
    inorderTraversal(root);
    cout << endl;
    return 0;
}
