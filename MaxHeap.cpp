//Max-Heap Implementation in C++ using Array

#include <iostream>
using namespace std;

class MaxHeap {
private:
    int *heap;  // Pointer to array representing the heap
    int capacity; // Maximum size of the heap
    int size; // Current number of elements

public:
    // Constructor
    MaxHeap(int cap) {
        capacity = cap;
        size = 0;
        heap = new int[capacity];
    }

    // Get index of parent, left child, and right child
    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return 2 * i + 1; }
    int right(int i) { return 2 * i + 2; }

    // Insert a new element into the heap
    void insert(int value) {
        if (size == capacity) {
            cout << "Heap is full!" << endl;
            return;
        }

        // Insert new value at the end
        int i = size;
        heap[size++] = value;

        // Heapify up (fix max-heap property)
        while (i != 0 && heap[parent(i)] < heap[i]) {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

    // Remove and return the maximum element (root)
    int extractMax() {
        if (size <= 0)
            return -1;
        if (size == 1)
            return heap[--size];

        int maxVal = heap[0];
        heap[0] = heap[--size]; // Move last element to root
        heapifyDown(0); // Heapify down to maintain heap property
        return maxVal;
    }

    // Heapify down (used after deletion)
    void heapifyDown(int i) {
        int largest = i;
        int l = left(i);
        int r = right(i);

        if (l < size && heap[l] > heap[largest])
            largest = l;
        if (r < size && heap[r] > heap[largest])
            largest = r;

        if (largest != i) {
            swap(heap[i], heap[largest]);
            heapifyDown(largest);
        }
    }

    // Print heap
    void printHeap() {
        for (int i = 0; i < size; i++)
            cout << heap[i] << " ";
        cout << endl;
    }

    // Destructor
    ~MaxHeap() {
        delete[] heap;
    }
};

// Main function
int main() {
    MaxHeap h(10);
    h.insert(15);
    h.insert(20);
    h.insert(30);
    h.insert(5);
    h.insert(10);
    h.insert(25);
    
    cout << "Heap elements: ";
    h.printHeap();

    cout << "Extracted max: " << h.extractMax() << endl;
    cout << "Heap after extraction: ";
    h.printHeap();

    return 0;
}


//Heap Data Structure (MaxHeap) – Implementation in C++
//A Max-Heap is a complete binary tree where the parent node is always greater than or equal to its children. It is typically implemented using an array.
//1. maxHeapify(int i)
void maxHeapify(int i) {
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int largest = i;

    if (left < heapSize && heap[left] > heap[largest])
        largest = left;
    if (right < heapSize && heap[right] > heap[largest])
        largest = right;

    if (largest != i) {
        std::swap(heap[i], heap[largest]);
        maxHeapify(largest);
    }
}

//2. buildHeap(std::vector<int>& seq)
void buildHeap(std::vector<int>& seq) {
    heap = seq;
    heapSize = heap.size();

    for (int i = heapSize / 2 - 1; i >= 0; i--) {
        maxHeapify(i);
    }
}

//3. T max()

int max() {
    if (heapSize == 0) throw std::underflow_error("Heap is empty");
    return heap[0];
}

//4. T removeMax()

int removeMax() {
    if (heapSize == 0) throw std::underflow_error("Heap is empty");

    int maxElement = heap[0];
    heap[0] = heap[heapSize - 1];
    heap.pop_back();
    heapSize--;

    maxHeapify(0);
    return maxElement;
}

//5. int length()

int length() {
    return heapSize;
}


//6. void increaseKey(int i, int k)

void increaseKey(int i, int k) {
    if (k < heap[i]) throw std::invalid_argument("New key is smaller than current key");

    heap[i] = k;
    while (i > 0 && heap[(i - 1) / 2] < heap[i]) {
        std::swap(heap[i], heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}


//7. void insert(int x)

void insert(int x) {
    heap.push_back(x);
    heapSize++;
    increaseKey(heapSize - 1, x);
}


//Full C++ implementation of MaxHeap
#include <iostream>
#include <vector>
#include <stdexcept>

class MaxHeap {
private:
    std::vector<int> heap;
    int heapSize;

    void maxHeapify(int i) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int largest = i;

        if (left < heapSize && heap[left] > heap[largest])
            largest = left;
        if (right < heapSize && heap[right] > heap[largest])
            largest = right;

        if (largest != i) {
            std::swap(heap[i], heap[largest]);
            maxHeapify(largest);
        }
    }

public:
    MaxHeap() : heapSize(0) {}

    void buildHeap(std::vector<int>& seq) {
        heap = seq;
        heapSize = heap.size();

        for (int i = heapSize / 2 - 1; i >= 0; i--) {
            maxHeapify(i);
        }
    }

    int max() {
        if (heapSize == 0) throw std::underflow_error("Heap is empty");
        return heap[0];
    }

    int removeMax() {
        if (heapSize == 0) throw std::underflow_error("Heap is empty");

        int maxElement = heap[0];
        heap[0] = heap[heapSize - 1];
        heap.pop_back();
        heapSize--;

        maxHeapify(0);
        return maxElement;
    }

    int length() {
        return heapSize;
    }

    void increaseKey(int i, int k) {
        if (k < heap[i]) throw std::invalid_argument("New key is smaller than current key");

        heap[i] = k;
        while (i > 0 && heap[(i - 1) / 2] < heap[i]) {
            std::swap(heap[i], heap[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    void insert(int x) {
        heap.push_back(x);
        heapSize++;
        increaseKey(heapSize - 1, x);
    }

    void printHeap() {
        for (int val : heap) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    MaxHeap heap;
    std::vector<int> arr = {23, 17, 14, 6, 13, 10, 15, 7, 12};

    heap.buildHeap(arr);
    heap.printHeap();

    std::cout << "Max: " << heap.max() << std::endl;

    heap.insert(50);
    heap.printHeap();

    std::cout << "Removed max: " << heap.removeMax() << std::endl;
    heap.printHeap();

    return 0;
}
