//Heap Sort Algorithm

HEAPSORT(A, m)  // m is the number of elements in A
1. n = m  // Set the heap size
2. BUILDHEAP(A, n)  // Convert the array into a max-heap
3. while n > 1:
4.     SWAP(A[0], A[n - 1])  // Move the largest element to the end
5.     n = n - 1  // Reduce the heap size
6.     MAXHEAPIFY(A, 0, n)  // Restore the heap property

//Non-Recursive Version of Heap Sort
//Since MAXHEAPIFY(A, i, n) is recursive, we can convert it into an iterative version using a loop:

void maxHeapify(vector<int>& A, int i, int n) {
    while (true) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && A[left] > A[largest]) largest = left;
        if (right < n && A[right] > A[largest]) largest = right;

        if (largest == i) break; // No swaps needed

        swap(A[i], A[largest]);
        i = largest; // Move down to maintain heap property
    }
}


//Complete Implementation of Heap Sort

#include <iostream>
#include <vector>
using namespace std;

void maxHeapify(vector<int>& A, int i, int n) {
    while (true) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && A[left] > A[largest]) largest = left;
        if (right < n && A[right] > A[largest]) largest = right;

        if (largest == i) break;

        swap(A[i], A[largest]);
        i = largest;
    }
}

void buildHeap(vector<int>& A, int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        maxHeapify(A, i, n);
    }
}

void heapSort(vector<int>& A) {
    int n = A.size();
    buildHeap(A, n);

    for (int i = n - 1; i > 0; i--) {
        swap(A[0], A[i]);
        maxHeapify(A, 0, i);
    }
}

int main() {
    vector<int> A = {4, 10, 3, 5, 1};
    
    heapSort(A);

    cout << "Sorted array: ";
    for (int x : A) cout << x << " ";
    return 0;
}


