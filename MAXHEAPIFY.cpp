//Algorithm: MAXHEAPIFY(A, i, n)

//Algorithm: MAXHEAPIFY(A, i, n)
void maxHeapify(vector<int>& A, int i, int n) {
    int left = 2 * i + 1;  // LEFT(i)
    int right = 2 * i + 2; // RIGHT(i)
    int max = i;

    if (left < n && A[max] < A[left])
        max = left;

    if (right < n && A[max] < A[right])
        max = right;

    if (max != i) {
        swap(A[i], A[max]);
        maxHeapify(A, max, n); // Recursive call
    }
}

//Algorithm (Non-Recursive)

void maxHeapifyIterative(vector<int>& A, int i, int n) {
    while (true) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int max = i;

        if (left < n && A[max] < A[left])
            max = left;

        if (right < n && A[max] < A[right])
            max = right;

        if (max == i)
            break; // Stop when heap property is restored

        swap(A[i], A[max]);
        i = max; // Move down to the swapped child's position
    }
}

//1. INCREASEKEY(A, i, k) Algorithm

void increaseKey(vector<int>& A, int i, int k) {
    if (k < A[i]) {
        throw invalid_argument("New key is smaller than current key");
    }

    A[i] = k;  // Update the value at index i

    int parent = (i - 1) / 2; // Get parent index

    // Bubble up until max-heap property is restored
    while (i > 0 && A[parent] < A[i]) {
        swap(A[i], A[parent]);
        i = parent;
        parent = (i - 1) / 2; // Update parent index
    }
}


//2. INSERT(A, n, val) Algorithm

void insert(vector<int>& A, int& n, int val) {
    A.push_back(INT_MIN); // Append a dummy value (-∞)
    n++; // Increase heap size
    increaseKey(A, n - 1, val); // Call increaseKey to set correct value and maintain heap property
}


