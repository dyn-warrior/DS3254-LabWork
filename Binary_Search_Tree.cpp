//1. Search Operation in BST

bool search(Node* node, int x) {
    if (node == nullptr) return false;
    if (node->data == x) return true;
    if (x < node->data) return search(node->left, x);
    return search(node->right, x);
}


//Iterative Approach

bool search(Node* node, int x) {
    while (node != nullptr) {
        if (node->data == x) return true;
        else if (x < node->data) node = node->left;
        else node = node->right;
    }
    return false;
}

//2. Insert Operation in BST

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};

Node* insert(Node* root, int x) {
    if (root == nullptr) return new Node(x);

    if (x < root->data) root->left = insert(root->left, x);
    else if (x > root->data) root->right = insert(root->right, x);

    return root;
}

//3. Delete Operation in BST

Node* getMin(Node* node) {
    while (node->left != nullptr) node = node->left;
    return node;
}

Node* deleteNode(Node* root, int x) {
    if (root == nullptr) return root;

    if (x < root->data) root->left = deleteNode(root->left, x);
    else if (x > root->data) root->right = deleteNode(root->right, x);
    else {
        // Case 1 & 2: No child / One child
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Case 3: Two children
        Node* temp = getMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}


//4. GetMin Operation

Node* getMin(Node* node) {
    while (node->left != nullptr) node = node->left;
    return node;
}


//5. Transplant Operation
//The TRANSPLANT(T, u, v) replaces node u with v.
void transplant(Node*& root, Node* u, Node* v) {
    if (u == root) root = v;
    else if (u == u->parent->left) u->parent->left = v;
    else u->parent->right = v;

    if (v != nullptr) v->parent = u->parent;
}


//Full Implementation of BST in C++

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};

class BST {
public:
    Node* root;

    BST() : root(nullptr) {}

    Node* insert(Node* node, int x) {
        if (node == nullptr) return new Node(x);
        if (x < node->data) node->left = insert(node->left, x);
        else if (x > node->data) node->right = insert(node->right, x);
        return node;
    }

    bool search(Node* node, int x) {
        while (node != nullptr) {
            if (node->data == x) return true;
            else if (x < node->data) node = node->left;
            else node = node->right;
        }
        return false;
    }

    Node* getMin(Node* node) {
        while (node->left != nullptr) node = node->left;
        return node;
    }

    Node* deleteNode(Node* node, int x) {
        if (node == nullptr) return node;
        if (x < node->data) node->left = deleteNode(node->left, x);
        else if (x > node->data) node->right = deleteNode(node->right, x);
        else {
            if (node->left == nullptr) return node->right;
            else if (node->right == nullptr) return node->left;
            Node* temp = getMin(node->right);
            node->data = temp->data;
            node->right = deleteNode(node->right, temp->data);
        }
        return node;
    }

    void inorder(Node* node) {
        if (node == nullptr) return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }
};

int main() {
    BST tree;
    tree.root = tree.insert(tree.root, 50);
    tree.insert(tree.root, 30);
    tree.insert(tree.root, 70);
    tree.insert(tree.root, 20);
    tree.insert(tree.root, 40);
    
    tree.inorder(tree.root);
    cout << endl;
    
    tree.root = tree.deleteNode(tree.root, 30);
    
    tree.inorder(tree.root);
}


