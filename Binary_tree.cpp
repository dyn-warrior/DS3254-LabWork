//C++ Implementation of a Node

#include <iostream>
using namespace std;

// Definition of a Tree Node
class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    // Constructor
    TreeNode(int value) {
        data = value;
        left = right = nullptr;
    }
};

// Basic Operations on Binary Tree
//BST Insertion

class BinaryTree {
public:
    TreeNode* root;

    BinaryTree() {
        root = nullptr;
    }

    // Recursive insertion in BST
    TreeNode* insert(TreeNode* node, int value) {
        if (node == nullptr) return new TreeNode(value);

        if (value < node->data)
            node->left = insert(node->left, value);
        else
            node->right = insert(node->right, value);

        return node;
    }

    void insert(int value) {
        root = insert(root, value);
    }
};


// Tree Traversal
//1. Inorder Traversal (Left, Root, Right)
void inorder(TreeNode* node) {
    if (node == nullptr) return;
    inorder(node->left);
    cout << node->data << " ";
    inorder(node->right);
}

//2. Preorder Traversal (Root, Left, Right)
void preorder(TreeNode* node) {
    if (node == nullptr) return;
    cout << node->data << " ";
    preorder(node->left);
    preorder(node->right);
}

//3. Postorder Traversal (Left, Right, Root)
void postorder(TreeNode* node) {
    if (node == nullptr) return;
    postorder(node->left);
    postorder(node->right);
    cout << node->data << " ";
}

//4. Level Order Traversal (BFS)

#include <queue>

void levelOrder(TreeNode* root) {
    if (!root) return;
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        cout << node->data << " ";

        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
    }
}


//BST Delete Function

TreeNode* minValueNode(TreeNode* node) {
    TreeNode* current = node;
    while (current && current->left)
        current = current->left;
    return current;
}

TreeNode* deleteNode(TreeNode* root, int key) {
    if (!root) return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        if (!root->left) {
            TreeNode* temp = root->right;
            delete root;
            return temp;
        } else if (!root->right) {
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }

        TreeNode* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}


//Finding the Height of a Binary Tree

int height(TreeNode* root) {
    if (!root) return -1;
    return max(height(root->left), height(root->right)) + 1;
}


// Searching in a Binary Tree

bool search(TreeNode* root, int key) {
    if (!root) return false;
    if (root->data == key) return true;
    if (key < root->data) return search(root->left, key);
    return search(root->right, key);
}


//complete code example

#include <iostream>
#include <queue>
using namespace std;

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) {
        data = value;
        left = right = nullptr;
    }
};

class BinaryTree {
public:
    TreeNode* root;

    BinaryTree() {
        root = nullptr;
    }

    TreeNode* insert(TreeNode* node, int value) {
        if (node == nullptr) return new TreeNode(value);
        if (value < node->data)
            node->left = insert(node->left, value);
        else
            node->right = insert(node->right, value);
        return node;
    }

    void insert(int value) {
        root = insert(root, value);
    }

    void inorder(TreeNode* node) {
        if (node == nullptr) return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    void preorder(TreeNode* node) {
        if (node == nullptr) return;
        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }

    void postorder(TreeNode* node) {
        if (node == nullptr) return;
        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
    }

    void levelOrder(TreeNode* root) {
        if (!root) return;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            cout << node->data << " ";
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
    }

    bool search(TreeNode* root, int key) {
        if (!root) return false;
        if (root->data == key) return true;
        if (key < root->data) return search(root->left, key);
        return search(root->right, key);
    }

    int height(TreeNode* root) {
        if (!root) return -1;
        return max(height(root->left), height(root->right)) + 1;
    }
};

int main() {
    BinaryTree tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(2);
    tree.insert(7);

    cout << "Inorder Traversal: ";
    tree.inorder(tree.root);
    cout << "\nPreorder Traversal: ";
    tree.preorder(tree.root);
    cout << "\nPostorder Traversal: ";
    tree.postorder(tree.root);
    cout << "\nLevel Order Traversal: ";
    tree.levelOrder(tree.root);

    cout << "\nHeight of Tree: " << tree.height(tree.root);
    cout << "\nSearch 7: " << (tree.search(tree.root, 7) ? "Found" : "Not Found");

    return 0;
}


// Definition of the Binary Tree

#include <iostream>
using namespace std;

template <class T>
class BinaryTree {
private:
    class Node {
    public:
        T data;
        Node* left;
        Node* right;

        // Constructor
        Node(const T& value) : data(value), left(nullptr), right(nullptr) {}
    };

    Node* root; // Root node of the tree

    // Helper function for recursive insertion
    Node* insert(Node* node, const T& value) {
        if (node == nullptr) return new Node(value);

        if (value < node->data)
            node->left = insert(node->left, value);
        else
            node->right = insert(node->right, value);

        return node;
    }

    // Helper functions for recursive traversal
    void inorder(Node* node) {
        if (node == nullptr) return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    void preorder(Node* node) {
        if (node == nullptr) return;
        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }

    void postorder(Node* node) {
        if (node == nullptr) return;
        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
    }

    // Search function
    bool search(Node* node, const T& key) {
        if (!node) return false;
        if (node->data == key) return true;
        return key < node->data ? search(node->left, key) : search(node->right, key);
    }

    // Function to find the height of the tree
    int height(Node* node) {
        if (!node) return -1;
        return max(height(node->left), height(node->right)) + 1;
    }

public:
    // Constructor
    BinaryTree() : root(nullptr) {}

    // Public function to insert a value
    void insert(const T& value) {
        root = insert(root, value);
    }

    // Public function for inorder traversal
    void inorder() {
        inorder(root);
        cout << endl;
    }

    // Public function for preorder traversal
    void preorder() {
        preorder(root);
        cout << endl;
    }

    // Public function for postorder traversal
    void postorder() {
        postorder(root);
        cout << endl;
    }

    // Public function to search for a key
    bool search(const T& key) {
        return search(root, key);
    }

    // Public function to get the height of the tree
    int height() {
        return height(root);
    }
};


// Tree Traversal Implementations
#include <iostream>
#include <unordered_map>
using namespace std;

template <class T>
class BinaryTree {
private:
    class Node {
    public:
        T data;
        Node* left;
        Node* right;

        // Constructor
        Node(const T& value) : data(value), left(nullptr), right(nullptr) {}
    };

    Node* root;

    // Recursive traversal functions
    void preorder(Node* node) {
        if (!node) return;
        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }

    void inorder(Node* node) {
        if (!node) return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    void postorder(Node* node) {
        if (!node) return;
        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
    }

public:
    BinaryTree() : root(nullptr) {}

    // Insert function (simple BST insert)
    void insert(const T& value) {
        root = insertRec(root, value);
    }

    // Traversal functions
    void preorder() {
        preorder(root);
        cout << endl;
    }

    void inorder() {
        inorder(root);
        cout << endl;
    }

    void postorder() {
        postorder(root);
        cout << endl;
    }

    // Function to construct a tree from preorder and inorder sequences
    BinaryTree(T preorder[], T inorder[], int size) {
        unordered_map<T, int> inorderIndex;
        for (int i = 0; i < size; i++) {
            inorderIndex[inorder[i]] = i;
        }
        int preIndex = 0;
        root = buildTree(preorder, inorder, preIndex, 0, size - 1, inorderIndex);
    }

private:
    // Recursive BST insert helper function
    Node* insertRec(Node* node, const T& value) {
        if (!node) return new Node(value);
        if (value < node->data)
            node->left = insertRec(node->left, value);
        else
            node->right = insertRec(node->right, value);
        return node;
    }

    // Recursive function to build tree from preorder & inorder
    Node* buildTree(T preorder[], T inorder[], int& preIndex, int inStart, int inEnd, unordered_map<T, int>& inorderIndex) {
        if (inStart > inEnd) return nullptr;

        T curr = preorder[preIndex++];
        Node* node = new Node(curr);
        
        if (inStart == inEnd) return node;

        int inIndex = inorderIndex[curr];

        node->left = buildTree(preorder, inorder, preIndex, inStart, inIndex - 1, inorderIndex);
        node->right = buildTree(preorder, inorder, preIndex, inIndex + 1, inEnd, inorderIndex);

        return node;
    }
};


// Using Tree Traversal and Construction
int main() {
    BinaryTree<int> tree;
    
    // Insert nodes
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(2);
    tree.insert(7);

    // Perform traversals
    cout << "Preorder: ";
    tree.preorder();

    cout << "Inorder: ";
    tree.inorder();

    cout << "Postorder: ";
    tree.postorder();

    // Construct tree from Preorder & Inorder sequences
    int preorder[] = {10, 5, 2, 7, 15};
    int inorder[] = {2, 5, 7, 10, 15};
    int size = 5;

    BinaryTree<int> constructedTree(preorder, inorder, size);

    cout << "Constructed Tree - Inorder: ";
    constructedTree.inorder();

    return 0;
}


//Binary tree array representation

#include <iostream>
using namespace std;

// Return the index of the left child of node at index i
int left(int i) {
    return 2 * i + 1;
}

// Return the index of the right child of node at index i
int right(int i) {
    return 2 * i + 2;
}

// Return the index of the parent of node at index i (for i > 0)
int parent(int i) {
    return (i - 1) / 2;
}

int main() {
    int i = 2;  // Example index
    cout << "For node at index " << i << ":" << endl;
    cout << "Left child index: " << left(i) << endl;
    cout << "Right child index: " << right(i) << endl;
    cout << "Parent index: " << parent(i) << endl;
    return 0;
}
