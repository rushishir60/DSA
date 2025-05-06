/*

Convert given binary tree into threaded binary tree. 
Analyze time and space complexity of the algorithm.*/


#include <iostream>
using namespace std;

// Forward declaration
class TBT;

class node {
    node *left, *right;
    int data;
    bool lbit, rbit;  // Flags to indicate if pointers are child (1) or thread (0)
public:
    node() {
        left = right = nullptr;
        lbit = rbit = 0;
    }
    node(int d) {
        data = d;
        left = right = nullptr;
        lbit = rbit = 0;
    }
    friend class TBT;
};

class TBT {
    node *root; // Dummy root node
public:
    TBT() {
        root = new node(9999); // Dummy node
        root->left = root;
        root->right = root;
        root->lbit = 0;
        root->rbit = 1;
    }

    void create();
    void insert(int data);
    node* inorder_suc(node *current);
    void inorder_traversal();
    node* preorder_suc(node *current);
    void preorder_traversal();
};

// Create tree by inserting multiple nodes
void TBT::create() {
    int n;
    if (root->left == root) {
        cout << "\nEnter number of nodes: ";
        cin >> n;
        for (int i = 0; i < n; i++) {
            int info;
            cout << "Enter data for node " << i + 1 << ": ";
            cin >> info;
            insert(info);
        }
    } else {
        cout << "\nTree already created.\n";
    }
}

// Insert a new node into the threaded binary tree
void TBT::insert(int data) {
    if (root->left == root) {
        node *p = new node(data);
        p->left = root;
        p->right = root;
        root->left = p;
        root->lbit = 1;
        cout << "Inserted root node: " << data << endl;
        return;
    }

    node *curr = root->left;
    while (true) {
        if (data < curr->data) {
            if (curr->lbit == 0) {
                node *p = new node(data);
                p->left = curr->left;
                p->right = curr;
                curr->left = p;
                curr->lbit = 1;
                cout << "Inserted to left of " << curr->data << ": " << data << endl;
                return;
            } else {
                curr = curr->left;
            }
        } else if (data > curr->data) {
            if (curr->rbit == 0) {
                node *p = new node(data);
                p->right = curr->right;
                p->left = curr;
                curr->right = p;
                curr->rbit = 1;
                cout << "Inserted to right of " << curr->data << ": " << data << endl;
                return;
            } else {
                curr = curr->right;
            }
        } else {
            cout << "Duplicate value not allowed: " << data << endl;
            return;
        }
    }
}

// Inorder traversal using threads
void TBT::inorder_traversal() {
    node *curr = root->left;
    while (curr->lbit == 1)
        curr = curr->left;

    cout << "\nInorder Traversal:\n";
    while (curr != root) {
        cout << curr->data << " ";
        curr = inorder_suc(curr);
    }
    cout << endl;
}

// Inorder successor using threads
node* TBT::inorder_suc(node *curr) {
    if (curr->rbit == 0)
        return curr->right;
    curr = curr->right;
    while (curr->lbit == 1)
        curr = curr->left;
    return curr;
}

// Preorder traversal using threads
void TBT::preorder_traversal() {
    node *curr = root->left;
    cout << "\nPreorder Traversal:\n";
    while (curr != root) {
        cout << curr->data << " ";
        curr = preorder_suc(curr);
    }
    cout << endl;
}

// Preorder successor using threads
node* TBT::preorder_suc(node *curr) {
    if (curr->lbit == 1)
        return curr->left;

    while (curr->rbit == 0 && curr->right != root)
        curr = curr->right;

    return curr->right;
}

// Main function
int main() {
    TBT tbt;
    int choice, value;

    do {
        cout << "\n--- Threaded Binary Tree Menu ---\n";
        cout << "1. Create Tree\n";
        cout << "2. Insert Node\n";
        cout << "3. Inorder Traversal\n";
        cout << "4. Preorder Traversal\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            tbt.create();
            break;
        case 2:
            cout << "Enter value to insert: ";
            cin >> value;
            tbt.insert(value);
            break;
        case 3:
            tbt.inorder_traversal();
            break;
        case 4:
            tbt.preorder_traversal();
            break;
        case 0:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice.\n";
        }
    } while (choice != 0);

    return 0;
}
