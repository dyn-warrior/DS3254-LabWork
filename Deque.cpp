//Deque (Double-Ended Queue) Implementation

#include <iostream>

template <class T>
class Deque {
private:
    T* _arr;
    int _front, _rear, _capacity;

public:
    // Constructor
    Deque(int cap) {
        _capacity = cap + 1;  // Extra space to differentiate full/empty states
        _arr = new T[_capacity];
        _front = _rear = 0;
    }

    // Destructor
    ~Deque() {
        delete[] _arr;
    }

    // Check if deque is empty
    bool is_empty() const {
        return _front == _rear;
    }

    // Check if deque is full
    bool is_full() const {
        return (_rear + 1) % _capacity == _front;
    }

    // Insert at the front
    void push_front(const T& val) {
        if (is_full()) {
            std::cout << "Deque is full\n";
            return;
        }
        _front = (_front - 1 + _capacity) % _capacity;
        _arr[_front] = val;
    }

    // Insert at the rear
    void push_back(const T& val) {
        if (is_full()) {
            std::cout << "Deque is full\n";
            return;
        }
        _arr[_rear] = val;
        _rear = (_rear + 1) % _capacity;
    }

    // Remove from the front
    T pop_front() {
        if (is_empty()) {
            throw std::underflow_error("Deque is empty");
        }
        T ret = _arr[_front];
        _front = (_front + 1) % _capacity;
        return ret;
    }

    // Remove from the rear
    T pop_back() {
        if (is_empty()) {
            throw std::underflow_error("Deque is empty");
        }
        _rear = (_rear - 1 + _capacity) % _capacity;
        return _arr[_rear];
    }

    // Get the front element
    T front() const {
        if (is_empty()) {
            throw std::out_of_range("Deque is empty");
        }
        return _arr[_front];
    }

    // Get the last element
    T back() const {
        if (is_empty()) {
            throw std::out_of_range("Deque is empty");
        }
        return _arr[(_rear - 1 + _capacity) % _capacity];
    }

    // Get the current size of the deque
    int size() const {
        return (_rear - _front + _capacity) % _capacity;
    }

    // Print the deque elements
    void print() const {
        std::cout << "Deque: ";
        for (int i = _front; i != _rear; i = (i + 1) % _capacity) {
            std::cout << _arr[i] << " ";
        }
        std::cout << "\n";
    }
};

//usage

int main() {
    Deque<int> dq(5);  // Deque with max size 5

    dq.push_back(10);
    dq.push_back(20);
    dq.push_front(5);
    dq.print();  // Deque: 5 10 20

    std::cout << "Front: " << dq.front() << "\n";  // 5
    std::cout << "Back: " << dq.back() << "\n";    // 20

    std::cout << "Popped front: " << dq.pop_front() << "\n";  // 5
    dq.print();  // Deque: 10 20

    dq.push_back(30);
    dq.push_back(40);
    dq.push_back(50); // Deque is full

    dq.print();  // Deque: 10 20 30 40

    std::cout << "Popped back: " << dq.pop_back() << "\n";  // 40
    dq.print();  // Deque: 10 20 30

    return 0;
}
