//Textbook naive method

#include <iostream>
#include <vector>
using namespace std;

// Function to multiply two polynomials
vector<int> multiplyPolynomials(const vector<int>& A, const vector<int>& B) {
    int n = A.size();
    int m = B.size();
    vector<int> result(n + m - 1, 0); // Resulting polynomial size is (n + m - 1)

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            result[i + j] += A[i] * B[j]; // Multiply and accumulate
        }
    }
    return result;
}

// Function to print polynomial
void printPolynomial(const vector<int>& poly) {
    for (int i = 0; i < poly.size(); i++) {
        if (poly[i] != 0) {
            cout << poly[i] << "x^" << i;
            if (i != poly.size() - 1) cout << " + ";
        }
    }
    cout << endl;
}

int main() {
    vector<int> A = {1, 2, 3}; // 1 + 2x + 3x^2
    vector<int> B = {4, 5};    // 4 + 5x

    vector<int> result = multiplyPolynomials(A, B);

    cout << "Resultant Polynomial: ";
    printPolynomial(result);

    return 0;
}

// Reducing the Number of Multiplications: Karatsuba’s Algorithm

#include <iostream>
#include <vector>
using namespace std;

// Function to multiply two polynomials using Karatsuba
vector<int> karatsubaMultiply(const vector<int>& A, const vector<int>& B) {
    int n = A.size();
    if (n == 1) {
        return {A[0] * B[0]};
    }

    int half = n / 2;
    vector<int> A_L(A.begin(), A.begin() + half);
    vector<int> A_H(A.begin() + half, A.end());
    vector<int> B_L(B.begin(), B.begin() + half);
    vector<int> B_H(B.begin() + half, B.end());

    vector<int> P1 = karatsubaMultiply(A_L, B_L);
    vector<int> P2 = karatsubaMultiply(A_H, B_H);
    
    vector<int> A_sum(half), B_sum(half);
    for (int i = 0; i < half; i++) {
        A_sum[i] = A_L[i] + A_H[i];
        B_sum[i] = B_L[i] + B_H[i];
    }

    vector<int> P3 = karatsubaMultiply(A_sum, B_sum);

    vector<int> result(2 * n - 1, 0);
    for (int i = 0; i < P1.size(); i++) result[i] += P1[i];
    for (int i = 0; i < P2.size(); i++) result[i + n] += P2[i];
    for (int i = 0; i < P3.size(); i++) result[i + half] += P3[i] - P1[i] - P2[i];

    return result;
}

int main() {
    vector<int> A = {1, 2, 3, 4};
    vector<int> B = {5, 6, 7, 8};

    vector<int> result = karatsubaMultiply(A, B);

    cout << "Resultant Polynomial: ";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << "x^" << i << " ";
        if (i != result.size() - 1) cout << "+ ";
    }
    cout << endl;

    return 0;
}
