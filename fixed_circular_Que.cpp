//Fixed Circular Queue Implementation

#include <iostream>

template <class T>
class CircularQueue {
private:
    T* _arr;
    int _front, _rear, _capacity;

public:
    // Constructor
    CircularQueue(int cap) {
        _capacity = cap + 1;  // Extra space to differentiate full/empty states
        _arr = new T[_capacity];
        _front = _rear = 0;
    }

    // Destructor
    ~CircularQueue() {
        delete[] _arr;
    }

    // Check if queue is empty
    bool is_empty() const {
        return _front == _rear;
    }

    // Check if queue is full
    bool is_full() const {
        return (_rear + 1) % _capacity == _front;
    }

    // Enqueue operation
    void enqueue(const T& val) {
        if (is_full()) {
            std::cout << "Queue is full\n";
            return;
        }
        _arr[_rear] = val;
        _rear = (_rear + 1) % _capacity;
    }

    // Dequeue operation
    T dequeue() {
        if (is_empty()) {
            throw std::underflow_error("Queue is empty");
        }
        T ret = _arr[_front];
        _front = (_front + 1) % _capacity;
        return ret;
    }

    // Get the first element
    T first() const {
        if (is_empty()) {
            throw std::out_of_range("Queue is empty");
        }
        return _arr[_front];
    }

    // Get the current size of the queue
    int size() const {
        return (_rear - _front + _capacity) % _capacity;
    }

    // Print the queue elements
    void print() const {
        std::cout << "Queue: ";
        for (int i = _front; i != _rear; i = (i + 1) % _capacity) {
            std::cout << _arr[i] << " ";
        }
        std::cout << "\n";
    }
};


//usage

int main() {
    CircularQueue<int> q(5);  // Queue with max size 5

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.print();  // Queue: 10 20 30

    std::cout << "First: " << q.first() << "\n";  // 10
    std::cout << "Dequeued: " << q.dequeue() << "\n";  // 10
    q.print();  // Queue: 20 30

    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);
    q.enqueue(70); // Queue is full

    q.print();  // Queue: 20 30 40 50 60

    return 0;
}
