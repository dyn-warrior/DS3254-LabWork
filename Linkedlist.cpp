//Linked List in C++ (Singly Linked List)
#include <iostream>

template <typename T>
class LinkedList {
private:
    class Node {  // Internal Node class
    public:
        T data;
        Node* next;
        Node(const T& value) : data(value), next(nullptr) {}  // Constructor
    };

    Node* head;
    Node* tail;
    int _length; // Stores the number of nodes

public:
    // Constructor
    LinkedList() {
        head = tail = nullptr;
        _length = 0;
    }

    // Destructor to free memory
    ~LinkedList() {
        Node* temp;
        while (head) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }

    // Append (Insert at end in O(1))
    void append(const T& value) {
        Node* newNode = new Node(value);
        if (!head) { // If list is empty
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        _length++;
    }

    // Prepend (Insert at beginning in O(1))
    void prepend(const T& value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
        _length++;
    }

//Doubly Linked List (DLL) in C++)

#include <iostream>

template <typename T>
class DoublyLinkedList {
private:
    // Node structure
    class Node {
    public:
        T data;
        Node* next;
        Node* prev;

        Node(const T& value) : data(value), next(nullptr), prev(nullptr) {}
    };

    Node* head;
    Node* tail;
    int _length;  // Stores the number of nodes

public:
    // Constructor
    DoublyLinkedList() {
        head = tail = nullptr;
        _length = 0;
    }

    // Destructor - Free memory
    ~DoublyLinkedList() {
        Node* temp;
        while (head) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }

    // Append: Insert at the end (O(1))
    void append(const T& value) {
        Node* newNode = new Node(value);
        if (!head) {  // If list is empty
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        _length++;
    }

    // Prepend: Insert at the beginning (O(1))
    void prepend(const T& value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        _length++;
    }

    // Remove a node with a given value (O(n))
    void remove(const T& value) {
        if (!head) return;  // Empty list

        Node* temp = head;
        while (temp && temp->data != value) {
            temp = temp->next;
        }

        if (!temp) return;  // Value not found

        if (temp == head) {  // If head is to be deleted
            head = head->next;
            if (head) head->prev = nullptr;
        } else if (temp == tail) {  // If tail is to be deleted
            tail = tail->prev;
            tail->next = nullptr;
        } else {  // Middle node
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
        }

        delete temp;
        _length--;

        if (_length == 0) head = tail = nullptr;  // List is empty
    }

    // Remove last element (O(1))
    void removeLast() {
        if (!tail) return; // Empty list

        Node* temp = tail;
        tail = tail->prev;

        if (tail) tail->next = nullptr;
        else head = nullptr;  // If only one element was present

        delete temp;
        _length--;
    }

    // Remove first element (O(1))
    void removeFirst() {
        if (!head) return; // Empty list

        Node* temp = head;
        head = head->next;

        if (head) head->prev = nullptr;
        else tail = nullptr;  // If only one element was present

        delete temp;
        _length--;
    }

    // Get list length (O(1))
    int length() const {
        return _length;
    }

    // Print forward (O(n))
    void printForward() const {
        Node* temp = head;
        while (temp) {
            std::cout << temp->data << " <-> ";
            temp = temp->next;
        }
        std::cout << "NULL\n";
    }

    // Print backward (O(n))
    void printBackward() const {
        Node* temp = tail;
        while (temp) {
            std::cout << temp->data << " <-> ";
            temp = temp->prev;
        }
        std::cout << "NULL\n";
    }
};

//Circular Linked List (CLL) in C++

#include <iostream>

template <typename T>
class CircularLinkedList {
private:
    class Node {
    public:
        T data;
        Node* next;

        Node(const T& value) : data(value), next(nullptr) {}
    };

    Node* tail;  // Instead of head, we store tail for easy insertion
    int _length;

public:
    // Constructor
    CircularLinkedList() {
        tail = nullptr;
        _length = 0;
    }

    // Destructor - Free memory
    ~CircularLinkedList() {
        if (!tail) return; // Empty list

        Node* temp = tail->next; // Start from head
        tail->next = nullptr;    // Break the circular link
        while (temp) {
            Node* nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }
    }

    // Append: Insert at the end (O(1))
    void append(const T& value) {
        Node* newNode = new Node(value);
        if (!tail) {  // If empty, point to itself
            tail = newNode;
            tail->next = tail;
        } else {
            newNode->next = tail->next; // New node points to head
            tail->next = newNode;       // Old tail points to new node
            tail = newNode;             // Update tail
        }
        _length++;
    }

    // Prepend: Insert at the beginning (O(1))
    void prepend(const T& value) {
        Node* newNode = new Node(value);
        if (!tail) {
            tail = newNode;
            tail->next = tail;
        } else {
            newNode->next = tail->next; // New node points to head
            tail->next = newNode;       // Tail points to new node
        }
        _length++;
    }

    // Remove a node with a given value (O(n))
    void remove(const T& value) {
        if (!tail) return;  // Empty list

        Node* current = tail->next; // Start from head
        Node* prev = tail;

        do {
            if (current->data == value) {  // Found the node
                if (current == tail && current->next == tail) { // Only one node
                    delete current;
                    tail = nullptr;
                } else {
                    prev->next = current->next;
                    if (current == tail) tail = prev; // Update tail if needed
                    delete current;
                }
                _length--;
                return;
            }
            prev = current;
            current = current->next;
        } while (current != tail->next);
    }

    // Remove last element (O(n) because we need to update tail)
    void removeLast() {
        if (!tail) return;

        Node* current = tail->next; // Start from head
        Node* prev = tail;

        while (current->next != tail->next) {
            prev = current;
            current = current->next;
        }

        if (current == tail) { // Only one node
            delete tail;
            tail = nullptr;
        } else {
            prev->next = tail->next;
            delete tail;
            tail = prev;
        }
        _length--;
    }

    // Remove first element (O(1))
    void removeFirst() {
        if (!tail) return;

        Node* head = tail->next;
        if (head == tail) { // Only one node
            delete tail;
            tail = nullptr;
        } else {
            tail->next = head->next; // Update tail to skip first node
            delete head;
        }
        _length--;
    }

    // Get length (O(1))
    int length() const {
        return _length;
    }

    // Print list (O(n))
    void print() const {
        if (!tail) {
            std::cout << "List is empty\n";
            return;
        }

        Node* temp = tail->next; // Start from head
        do {
            std::cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != tail->next);
        std::cout << "(back to head)\n";
    }
};


    // Remove (Delete a node with a given value in O(n))
    void remove(const T& value) {
        if (!head) return; // List is empty

        // If head needs to be deleted
        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            _length--;
            if (!head) tail = nullptr; // If list becomes empty
            return;
        }

        // Search for the node to delete
        Node* temp = head;
        while (temp->next && temp->next->data != value) {
            temp = temp->next;
        }

        if (temp->next) { // If found
            Node* toDelete = temp->next;
            temp->next = temp->next->next;
            if (!temp->next) tail = temp; // If last node was deleted
            delete toDelete;
            _length--;
        }
    }

    // Remove last element (O(n) due to traversal)
    void removeLast() {
        if (!head) return; // List is empty

        if (head == tail) { // Single element case
            delete head;
            head = tail = nullptr;
        } else {
            Node* temp = head;
            while (temp->next != tail) { // Find second last node
                temp = temp->next;
            }
            delete tail;
            tail = temp;
            tail->next = nullptr;
        }
        _length--;
    }

    // Remove first element (O(1))
    void removeFirst() {
        if (!head) return; // List is empty
        Node* temp = head;
        head = head->next;
        delete temp;
        _length--;
        if (!head) tail = nullptr; // If list becomes empty
    }

    // Return length (O(1))
    int length() const {
        return _length;
    }

    // Print the list (O(n))
    void print() const {
        Node* temp = head;
        while (temp) {
            std::cout << temp->data << " -> ";
            temp = temp->next;
        }
        std::cout << "NULL\n";
    }
};
