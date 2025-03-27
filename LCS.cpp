//C++ Code: LCS with Reconstruction

#include <bits/stdc++.h>
using namespace std;

// LCS function that returns both the length of the LCS and the actual LCS string
pair<int, string> LCS(const string& X, const string& Y) {
    int m = (int)X.size();
    int n = (int)Y.size();

    // c[i][j] will hold the length of the LCS of X[0..i-1] and Y[0..j-1]
    vector<vector<int>> c(m + 1, vector<int>(n + 1, 0));

    // Build the c[][] table in bottom-up fashion
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i - 1] == Y[j - 1]) {
                c[i][j] = c[i - 1][j - 1] + 1;
            } else {
                c[i][j] = max(c[i - 1][j], c[i][j - 1]);
            }
        }
    }

    // Length of LCS is now c[m][n]
    int lcs_length = c[m][n];

    // Reconstruct the LCS from the table c[][]
    // We'll start from c[m][n] and move backwards
    int i = m, j = n;
    string lcs_str;

    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            // If characters match, this character is part of the LCS
            lcs_str.push_back(X[i - 1]);
            i--;
            j--;
        }
        else {
            // Move in the direction of the larger value
            if (c[i - 1][j] > c[i][j - 1]) {
                i--;
            } else {
                j--;
            }
        }
    }

    // Since we constructed lcs_str backwards, reverse it
    reverse(lcs_str.begin(), lcs_str.end());

    // Return both length and the LCS string
    return make_pair(lcs_length, lcs_str);
}

int main() {
    // Example usage:
    string X, Y;
    cout << "Enter first sequence (string): ";
    cin >> X;
    cout << "Enter second sequence (string): ";
    cin >> Y;

    // Compute LCS
    pair<int, string> result = LCS(X, Y);

    // Print results
    cout << "Length of LCS: " << result.first << endl;
    cout << "LCS: " << result.second << endl;

    return 0;
}


