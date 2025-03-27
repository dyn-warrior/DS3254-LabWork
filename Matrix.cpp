//Complete Matrix Class Implementation in C++

#include <iostream>

class Matrix {
private:
    int rows, cols;
    float** _mat; // Pointer to a 2D dynamic array

public:
    // Constructor: Initializes matrix with given rows and cols
    Matrix(int r, int c) : rows(r), cols(c) {
        _mat = new float*[rows];
        for (int i = 0; i < rows; i++) {
            _mat[i] = new float[cols]{0}; // Initialize with zeros
        }
    }

    // Destructor: Frees dynamically allocated memory
    ~Matrix() {
        for (int i = 0; i < rows; i++) {
            delete[] _mat[i];
        }
        delete[] _mat;
    }

    // Overloaded operator[] to access row elements
    float* operator[](const int i) { 
        return _mat[i]; 
    }

    // Get number of rows
    int numRows() const { return rows; }

    // Get number of columns
    int numCols() const { return cols; }

    // Overloaded output stream operator to print matrix
    friend std::ostream& operator<<(std::ostream& out, const Matrix& m) {
        for (int i = 0; i < m.rows; i++) {
            for (int j = 0; j < m.cols; j++) {
                out << m._mat[i][j] << " ";
            }
            out << std::endl;
        }
        return out;
    }
};

// Main function to demonstrate Matrix usage
int main() {
    Matrix m(4, 5); // Create a 4x5 matrix

    // Fill the matrix with values (i + j + 1)
    for (int i = 0; i < m.numRows(); i++) {
        for (int j = 0; j < m.numCols(); j++) {
            m[i][j] = i + j + 1;
        }
    }

    // Print the matrix
    std::cout << "Matrix:\n" << m;

    return 0;
}


// Matrix Using a 1-D Array

//Instead of storing elements in a float** (2D array), we store them in a 1D array and map (i, j) → index using the formula: index=i×cols+j

#include <iostream>
#include <vector>

class Matrix1D {
private:
    int rows, cols;
    std::vector<float> data; // 1D storage

public:
    // Constructor: Initializes matrix with given rows and cols
    Matrix1D(int r, int c) : rows(r), cols(c), data(r * c, 0) {}

    // Access element (i, j)
    float& operator()(int i, int j) {
        return data[i * cols + j];
    }

    // Get number of rows
    int numRows() const { return rows; }

    // Get number of cols
    int numCols() const { return cols; }

    // Print matrix
    void print() const {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                std::cout << data[i * cols + j] << " ";
            }
            std::cout << std::endl;
        }
    }
};

// Main function
int main() {
    Matrix1D m(4, 5);

    // Fill the matrix
    for (int i = 0; i < m.numRows(); i++) {
        for (int j = 0; j < m.numCols(); j++) {
            m(i, j) = i + j + 1;
        }
    }

    // Print the matrix
    std::cout << "Matrix stored in 1D array:\n";
    m.print();

    return 0;
}

//Sparse Matrix Using Array/Vector of Pairs

//A sparse matrix contains mostly zeroes, so we store only nonzero elements as (row, col, value) tuples using a std::vector<std::tuple<int, int, float>>.

#include <iostream>
#include <vector>
#include <tuple>

class SparseMatrix {
private:
    int rows, cols;
    std::vector<std::tuple<int, int, float>> elements; // Stores (row, col, value)

public:
    // Constructor
    SparseMatrix(int r, int c) : rows(r), cols(c) {}

    // Insert a value at (i, j)
    void insert(int i, int j, float value) {
        if (value != 0) { // Store only nonzero values
            elements.emplace_back(i, j, value);
        }
    }

    // Print sparse representation
    void print() const {
        std::cout << "Sparse Matrix Representation (row, col, value):\n";
        for (const auto& [r, c, v] : elements) {
            std::cout << "(" << r << ", " << c << ", " << v << ")\n";
        }
    }
};

// Main function
int main() {
    SparseMatrix sm(4, 5);

    // Insert only nonzero values
    sm.insert(0, 1, 5);
    sm.insert(1, 3, 8);
    sm.insert(2, 2, 3);
    sm.insert(3, 4, 7);

    // Print sparse matrix
    sm.print();

    return 0;
}
