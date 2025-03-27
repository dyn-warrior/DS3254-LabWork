//Insert/Append in Vector
//When inserting at the end:
//If there is space (_size < _capacity), we simply append.
//If _size == _capacity, we double the capacity and copy old elements.template <class T>
void push_back(T value) {
    if (_size == _capacity) {  // Need to expand
        _capacity *= 2;
        T* newArr = new T[_capacity];

        for (int i = 0; i < _size; i++) {
            newArr[i] = _arr[i];
        }

        delete[] _arr; // Free old memory
        _arr = newArr;
    }

    _arr[_size] = value;  
    _size++;
}


//Deletion in Vector
//Deleting from the end (pop_back) is O(1).
//Deleting from the middle (erase(index)) is O(n) because elements need shifting.

template <class T>
void pop_back() {
    if (_size > 0) {
        _size--;
    }
}

template <class T>
void erase(int index) {
    if (index < 0 || index >= _size) {
        throw std::out_of_range("Index out of bounds");
    }

    for (int i = index; i < _size - 1; i++) {
        _arr[i] = _arr[i + 1]; // Shift elements left
    }

    _size--;
}


//Vector (Stretchable Array) Implementation


template <class T>
class Vector {
private:
    T* _arr;
    int _capacity;
    int _size;

    // Function to revise capacity
    void revise_capacity(int new_cap) {
        T* new_arr = new T[new_cap];
        for (int i = 0; i < _size; i++) {
            new_arr[i] = _arr[i];  // Copy elements
        }
        delete[] _arr;  // Free old memory
        _arr = new_arr;
        _capacity = new_cap;
    }

public:
    Vector(int cap = 1) {
        _arr = new T[cap];
        _capacity = cap;
        _size = 0;
    }

    // Append function
    void append(const T& elem) {
        if (_capacity == _size) {  // Stretch when full
            revise_capacity(2 * _capacity);
        }
        _arr[_size] = elem;
        _size++;
    }

    // Remove last element and shrink if needed
    int removeLast() {
        if (_size == 0) throw std::out_of_range("Vector is empty");
        int ret = _arr[_size - 1];
        _size--;

        if (_size == _capacity / 4) {  // Shrink when 25% full
            revise_capacity(_capacity / 2);
        }

        return ret;
    }
};
