//Queue Using Linked List
//This implementation supports dynamic queue operations.

#include <iostream>

template <typename T>
class LinkedListQueue {
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
    LinkedListQueue() {
        frontNode = rearNode = nullptr;
        _size = 0;
    }

    // Destructor
    ~LinkedListQueue() {
        while (!is_empty()) {
            dequeue();
        }
    }

    // Enqueue: O(1)
    void enqueue(const T& x) {
        Node* newNode = new Node(x);
        if (is_empty()) {
            frontNode = rearNode = newNode;
        } else {
            rearNode->next = newNode;
            rearNode = newNode;
        }
        _size++;
    }

    // Dequeue: O(1)
    T dequeue() {
        if (is_empty()) {
            throw std::underflow_error("Queue Underflow: Cannot dequeue from an empty queue");
        }
        Node* temp = frontNode;
        T value = frontNode->data;
        frontNode = frontNode->next;
        delete temp;
        _size--;

        if (is_empty()) {
            rearNode = nullptr;
        }
        return value;
    }

    // First: O(1)
    T first() const {
        if (is_empty()) {
            throw std::out_of_range("Queue is empty");
        }
        return frontNode->data;
    }

    // Size: O(1)
    int size() const {
        return _size;
    }

    // Check if empty: O(1)
    bool is_empty() const {
        return _size == 0;
    }

    // Print queue elements: O(n)
    void print() const {
        std::cout << "Queue: ";
        Node* temp = frontNode;
        while (temp) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << "\n";
    }
};


//usage

int main() {
    LinkedListQueue<int> q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.print();  // Queue: 10 20 30

    std::cout << "First: " << q.first() << "\n";  // 10
    std::cout << "Dequeued: " << q.dequeue() << "\n";  // 10
    q.print();  // Queue: 20 30

    return 0;
}

//Queue Using Bounded Circular Array
//This implementation supports dynamic queue operations.

#include <iostream>

template <typename T>
class CircularQueue {
private:
    T* _arr;
    int _capacity;
    int _size;
    int _front;
    int _rear;

public:
    // Constructor
    CircularQueue(int cap) {
        _capacity = cap;
        _arr = new T[_capacity];
        _size = 0;
        _front = 0;
        _rear = -1;
    }

    // Destructor
    ~CircularQueue() {
        delete[] _arr;
    }

    // Enqueue: O(1)
    void enqueue(const T& x) {
        if (is_full()) {
            throw std::overflow_error("Queue Overflow: Cannot enqueue into a full queue");
        }
        _rear = (_rear + 1) % _capacity;
        _arr[_rear] = x;
        _size++;
    }

    // Dequeue: O(1)
    T dequeue() {
        if (is_empty()) {
            throw std::underflow_error("Queue Underflow: Cannot dequeue from an empty queue");
        }
        T value = _arr[_front];
        _front = (_front + 1) % _capacity;
        _size--;
        return value;
    }

    // First: O(1)
    T first() const {
        if (is_empty()) {
            throw std::out_of_range("Queue is empty");
        }
        return _arr[_front];
    }

    // Size: O(1)
    int size() const {
        return _size;
    }

    // Check if full: O(1)
    bool is_full() const {
        return _size == _capacity;
    }

    // Check if empty: O(1)
    bool is_empty() const {
        return _size == 0;
    }

    // Print queue elements: O(n)
    void print() const {
        std::cout << "Queue: ";
        for (int i = 0; i < _size; i++) {
            std::cout << _arr[(_front + i) % _capacity] << " ";
        }
        std::cout << "\n";
    }
};


//usage

int main() {
    CircularQueue<int> q(5);  // Queue with fixed size 5

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.print();  // Queue: 10 20 30

    std::cout << "First: " << q.first() << "\n";  // 10
    std::cout << "Dequeued: " << q.dequeue() << "\n";  // 10
    q.print();  // Queue: 20 30

    return 0;
}


//Queue using Bounded Array (Circular Queue)

//A bounded queue has a fixed size and operates in a circular manner to optimize space.

#include <iostream>

template <typename T>
class BoundedQueue {
private:
    T* _arr;
    int _capacity;
    int _size;
    int _front;
    int _rear;

public:
    // Constructor
    BoundedQueue(int cap) {
        _capacity = cap;
        _arr = new T[_capacity];
        _size = 0;
        _front = 0;
        _rear = -1;
    }

    // Destructor
    ~BoundedQueue() {
        delete[] _arr;
    }

    // Enqueue operation: O(1)
    void enqueue(const T& x) {
        if (is_full()) {
            throw std::overflow_error("Queue Overflow: Cannot enqueue into a full queue");
        }
        _rear = (_rear + 1) % _capacity;
        _arr[_rear] = x;
        _size++;
    }

    // Dequeue operation: O(1)
    T dequeue() {
        if (is_empty()) {
            throw std::underflow_error("Queue Underflow: Cannot dequeue from an empty queue");
        }
        T value = _arr[_front];
        _front = (_front + 1) % _capacity;
        _size--;
        return value;
    }

    // First operation: O(1)
    T first() const {
        if (is_empty()) {
            throw std::out_of_range("Queue is empty");
        }
        return _arr[_front];
    }

    // Size operation: O(1)
    int size() const {
        return _size;
    }

    // Check if full: O(1)
    bool is_full() const {
        return _size == _capacity;
    }

    // Check if empty: O(1)
    bool is_empty() const {
        return _size == 0;
    }

    // Print queue elements: O(n)
    void print() const {
        std::cout << "Queue: ";
        for (int i = 0; i < _size; i++) {
            std::cout << _arr[(_front + i) % _capacity] << " ";
        }
        std::cout << "\n";
    }
};


//usage

int main() {
    BoundedQueue<int> q(5);  // Queue with fixed size 5

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.print();  // Queue: 10 20 30

    std::cout << "First: " << q.first() << "\n";  // 10
    std::cout << "Dequeued: " << q.dequeue() << "\n";  // 10
    q.print();  // Queue: 20 30

    std::cout << "Size: " << q.size() << "\n";  // 2
    std::cout << (q.is_empty() ? "Queue is empty\n" : "Queue is not empty\n");

    return 0;
}


// Queue using Bounded Linked List

//A bounded queue using a linked list limits the number of nodes.

#include <iostream>

template <typename T>
class BoundedQueueLL {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& value) : data(value), next(nullptr) {}
    };

    Node* frontNode;
    Node* rearNode;
    int _size;
    int _capacity;  // Fixed capacity

public:
    // Constructor
    BoundedQueueLL(int cap) {
        frontNode = rearNode = nullptr;
        _size = 0;
        _capacity = cap;
    }

    // Destructor
    ~BoundedQueueLL() {
        while (!is_empty()) {
            dequeue();
        }
    }

    // Enqueue operation: O(1)
    void enqueue(const T& x) {
        if (is_full()) {
            throw std::overflow_error("Queue Overflow: Cannot enqueue into a full queue");
        }
        Node* newNode = new Node(x);
        if (is_empty()) {
            frontNode = rearNode = newNode;
        } else {
            rearNode->next = newNode;
            rearNode = newNode;
        }
        _size++;
    }

    // Dequeue operation: O(1)
    T dequeue() {
        if (is_empty()) {
            throw std::underflow_error("Queue Underflow: Cannot dequeue from an empty queue");
        }
        Node* temp = frontNode;
        T value = frontNode->data;
        frontNode = frontNode->next;
        delete temp;
        _size--;
        if (is_empty()) {
            rearNode = nullptr;
        }
        return value;
    }

    // First operation: O(1)
    T first() const {
        if (is_empty()) {
            throw std::out_of_range("Queue is empty");
        }
        return frontNode->data;
    }

    // Size operation: O(1)
    int size() const {
        return _size;
    }

    // Check if full: O(1)
    bool is_full() const {
        return _size == _capacity;
    }

    // Check if empty: O(1)
    bool is_empty() const {
        return _size == 0;
    }

    // Print queue elements: O(n)
    void print() const {
        std::cout << "Queue: ";
        Node* temp = frontNode;
        while (temp) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << "\n";
    }
};

//usage

int main() {
    BoundedQueueLL<int> q(3);  // Queue with fixed size 3

    q.enqueue(10);
    q.enqueue(20);
    q.print();  // Queue: 10 20

    std::cout << "First: " << q.first() << "\n";  // 10
    std::cout << "Dequeued: " << q.dequeue() << "\n";  // 10
    q.print();  // Queue: 20

    q.enqueue(30);
    q.enqueue(40);
    q.print();  // Queue: 20 30 40

    return 0;
}
