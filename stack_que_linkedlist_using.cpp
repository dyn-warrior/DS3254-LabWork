// Stack ADT using Array/Vector

#include <iostream>
#include <vector>

template <typename T>
class Stack {
private:
    std::vector<T> arr; // Using vector to dynamically manage elements

public:
    // Push operation (O(1))
    void push(const T& value) {
        arr.push_back(value);
    }

    // Pop operation (O(1))
    T pop() {
        if (arr.empty()) {
            throw std::underflow_error("Stack is empty");
        }
        T value = arr.back();
        arr.pop_back();
        return value;
    }

    // Top operation (O(1))
    T top() {
        if (arr.empty()) {
            throw std::underflow_error("Stack is empty");
        }
        return arr.back();
    }

    // Size of stack (O(1))
    int size() {
        return arr.size();
    }

    // Check if empty (O(1))
    bool is_empty() {
        return arr.empty();
    }

    // Print stack elements
    void print() {
        std::cout << "Stack: ";
        for (const T& elem : arr) {
            std::cout << elem << " ";
        }
        std::cout << "\n";
    }
};

// Example usage
int main() {
    Stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.print();
    std::cout << "Popped: " << s.pop() << "\n";
    s.print();
    return 0;
}


// Stack ADT using Linked List

#include <iostream>

template <typename T>
class Stack {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& value) : data(value), next(nullptr) {}
    };

    Node* topNode;
    int _size;

public:
    // Constructor
    Stack() : topNode(nullptr), _size(0) {}

    // Destructor to free memory
    ~Stack() {
        while (!is_empty()) {
            pop();
        }
    }

    // Push (O(1))
    void push(const T& value) {
        Node* newNode = new Node(value);
        newNode->next = topNode;
        topNode = newNode;
        _size++;
    }

    // Pop (O(1))
    T pop() {
        if (is_empty()) {
            throw std::underflow_error("Stack is empty");
        }
        Node* temp = topNode;
        T value = temp->data;
        topNode = topNode->next;
        delete temp;
        _size--;
        return value;
    }

    // Top (O(1))
    T top() {
        if (is_empty()) {
            throw std::underflow_error("Stack is empty");
        }
        return topNode->data;
    }

    // Size (O(1))
    int size() {
        return _size;
    }

    // Check if empty (O(1))
    bool is_empty() {
        return topNode == nullptr;
    }

    // Print elements
    void print() {
        Node* temp = topNode;
        std::cout << "Stack: ";
        while (temp) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << "\n";
    }
};

// Example usage
int main() {
    Stack<int> s;
    s.push(5);
    s.push(15);
    s.push(25);
    s.print();
    std::cout << "Popped: " << s.pop() << "\n";
    s.print();
    return 0;
}

// Queue ADT using Linked List

#include <iostream>

template <typename T>
class Queue {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& value) : data(value), next(nullptr) {}
    };

    Node* frontNode;
    Node* rearNode;
    int _size;

public:
    // Constructor
    Queue() : frontNode(nullptr), rearNode(nullptr), _size(0) {}

    // Destructor
    ~Queue() {
        while (!is_empty()) {
            dequeue();
        }
    }

    // Enqueue (O(1))
    void enqueue(const T& value) {
        Node* newNode = new Node(value);
        if (is_empty()) {
            frontNode = rearNode = newNode;
        } else {
            rearNode->next = newNode;
            rearNode = newNode;
        }
        _size++;
    }

    // Dequeue (O(1))
    T dequeue() {
        if (is_empty()) {
            throw std::underflow_error("Queue is empty");
        }
        Node* temp = frontNode;
        T value = temp->data;
        frontNode = frontNode->next;
        if (!frontNode) rearNode = nullptr; // If queue becomes empty
        delete temp;
        _size--;
        return value;
    }

    // Get front element (O(1))
    T front() {
        if (is_empty()) {
            throw std::underflow_error("Queue is empty");
        }
        return frontNode->data;
    }

    // Get size (O(1))
    int size() {
        return _size;
    }

    // Check if empty (O(1))
    bool is_empty() {
        return frontNode == nullptr;
    }

    // Print elements
    void print() {
        Node* temp = frontNode;
        std::cout << "Queue: ";
        while (temp) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << "\n";
    }
};

// Example usage
int main() {
    Queue<int> q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.print();
    std::cout << "Dequeued: " << q.dequeue() << "\n";
    q.print();
    return 0;
}
