//Huffman Coding Algorithm
//Algorithm: Constructing Huffman Code

struct Node {
    char ch;
    int freq;
    Node *left, *right;
    
    Node(char ch, int freq) {
        this->ch = ch;
        this->freq = freq;
        left = right = nullptr;
    }
};

// Custom comparator for priority queue
struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq; // Min-Heap based on frequency
    }
};

Node* HUFFMAN(vector<pair<char, int>> &C) {
    priority_queue<Node*, vector<Node*>, Compare> Q;

    // Step 1: Insert all characters into the priority queue
    for (auto &p : C) 
        Q.push(new Node(p.first, p.second));

    // Step 2: Build Huffman Tree
    while (Q.size() > 1) {
        Node *x = Q.top(); Q.pop();
        Node *y = Q.top(); Q.pop();
        
        Node *z = new Node('$', x->freq + y->freq);
        z->left = x;
        z->right = y;
        
        Q.push(z);
    }
    return Q.top(); // Root of Huffman Tree
}


