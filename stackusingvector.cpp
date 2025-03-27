//Implementation: Stack using Dynamic Array (Vector)


#include <iostream>

template <typename T>
class Stack {
private:
    T* _arr;         // Array to store stack elements
    int _capacity;   // Maximum capacity of stack
    int _size;       // Current size of stack

    // Function to increase capacity dynamically
    void resize(int new_capacity) {
        T* new_arr = new T[new_capacity];
        for (int i = 0; i < _size; i++) {
            new_arr[i] = _arr[i];
        }
        delete[] _arr;
        _arr = new_arr;
        _capacity = new_capacity;
    }

public:
    // Constructor
    Stack(int cap = 2) {
        _arr = new T[cap];
        _capacity = cap;
        _size = 0;
    }

    // Destructor
    ~Stack() {
        delete[] _arr;
    }

    // Push operation (O(1) amortized)
    void push(const T& x) {
        if (_size == _capacity) { // Resize if full
            resize(2 * _capacity);
        }
        _arr[_size++] = x;
    }

    // Pop operation (O(1))
    T pop() {
        if (is_empty()) {
            throw std::out_of_range("Stack Underflow");
        }
        return _arr[--_size];
    }

    // Top operation (O(1))
    T top() const {
        if (is_empty()) {
            throw std::out_of_range("Stack is empty");
        }
        return _arr[_size - 1];
    }

    // Size operation (O(1))
    int size() const {
        return _size;
    }

    // Check if stack is full (not relevant for dynamic array)
    bool is_full() const {
        return false; // Since resizing is dynamic, it never gets "full"
    }

    // Check if stack is empty (O(1))
    bool is_empty() const {
        return _size == 0;
    }

    // Print Stack Elements (O(n))
    void print() const {
        std::cout << "Stack: ";
        for (int i = 0; i < _size; i++) {
            std::cout << _arr[i] << " ";
        }
        std::cout << "\n";
    }
};


//Example usage 

int main() {
    Stack<int> s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.print();  // Stack: 10 20 30

    std::cout << "Top: " << s.top() << "\n";  // 30
    std::cout << "Popped: " << s.pop() << "\n";  // 30
    s.print();  // Stack: 10 20

    std::cout << "Size: " << s.size() << "\n";  // 2
    std::cout << (s.is_empty() ? "Stack is empty\n" : "Stack is not empty\n");

    return 0;
}
