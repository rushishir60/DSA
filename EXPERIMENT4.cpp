/*
Beginning with an empty binary search tree,
 Construct binary search tree by inserting the values in the order given. 
 After constructing a binary tree - 
 i. Insert new node, 
 ii. Find number of nodes in longest path from root,
  iii. Minimum data value found in the tree,
iv. Change a tree so that the roles of the left and right pointers are swapped at every node, 
v. Search a value
*/




#include <iostream>
using namespace std;

// Node structure for the BST
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Function to create a new node
Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

// Function to insert a value in BST
Node* insert(Node* root, int value) {
    if (root == nullptr) {
        return createNode(value);
    }
    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);
    return root;
}

// In-order traversal to display BST
void inorder(Node* root) {
    if (root != nullptr) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

// Function to find height (longest path from root)
int height(Node* root) {
    if (root == nullptr)
        return 0;
    int lHeight = height(root->left);
    int rHeight = height(root->right);
    return max(lHeight, rHeight) + 1;
}

// Function to find minimum value in BST
int findMin(Node* root) {
    if (root == nullptr) {
        cout << "Tree is empty.\n";
        return -1;
    }
    while (root->left != nullptr)
        root = root->left;
    return root->data;
}

// Function to mirror the tree (swap left and right)
void mirror(Node* root) {
    if (root == nullptr)
        return;
    mirror(root->left);
    mirror(root->right);
    swap(root->left, root->right);
}

// Function to search for a value in BST
bool search(Node* root, int key) {
    if (root == nullptr)
        return false;
    if (root->data == key)
        return true;
    else if (key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}

// Main function with menu-driven interface
int main() {
    Node* root = nullptr;
    int n, value, choice;

    // Input initial elements to construct the BST
    cout << "Enter number of initial elements: ";
    cin >> n;
    cout << "Enter values: ";
    for (int i = 0; i < n; ++i) {
        cin >> value;
        root = insert(root, value);
    }

    // Menu-driven operations
    do {
        cout << "\n--- Binary Search Tree Operations ---\n";
        cout << "1. Insert new node\n";
        cout << "2. Find height (longest path from root)\n";
        cout << "3. Find minimum value\n";
        cout << "4. Mirror the tree\n";
        cout << "5. Search a value\n";
        cout << "6. Display Inorder\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                root = insert(root, value);
                break;
            case 2:
                cout << "Height of tree: " << height(root) << endl;
                break;
            case 3:
                cout << "Minimum value: " << findMin(root) << endl;
                break;
            case 4:
                mirror(root);
                cout << "Tree mirrored successfully.\n";
                break;
            case 5:
                cout << "Enter value to search: ";
                cin >> value;
                cout << (search(root, value) ? "Value found.\n" : "Value not found.\n");
                break;
            case 6:
                cout << "Inorder Traversal: ";
                inorder(root);
                cout << endl;
                break;
            case 0:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid option. Try again.\n";
        }
    } while (choice != 0);

    return 0;
}
