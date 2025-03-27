//Matrix Chain Multiplication: Recursive Algorithm (Top-Down Approach)

MATRIXCHAINRECURSIVE(P, i, j)
1   if i == j
2       return 0
3   m[i, j] = ∞
4   for k = i to j-1
5       q = MATRIXCHAINRECURSIVE(P, i, k) +
           MATRIXCHAINRECURSIVE(P, k+1, j) + P[i-1] * P[k] * P[j]
6       if q < m[i, j]
7           m[i, j] = q
8   return m[i, j]


//Matrix Chain Multiplication: Recursive Algorithm with Memoization (Top-Down DP)
//Algorithm Explanation
//The memoized recursive approach avoids redundant computations by storing results in a table m[i,j]m[i,j], which helps in reducing the number of recursive calls.

  MEMOIZEDMATRIXCHAIN(P, n)
1   Let m[1...n, 1...n] be a new table
2   for i = 1 to n
3       m[i, i] = 0   // Cost of multiplying a single matrix is 0
4   for j = i+1 to n
5       m[i, j] = ∞
6   return LOOKUPCHAIN(P, m, 1, n)

LOOKUPCHAIN(P, m, i, j)
1   if m[i, j] < ∞ then return m[i, j]  // If already computed, return stored value
2   for k = i to j-1
3       q = LOOKUPCHAIN(P, m, i, k) + LOOKUPCHAIN(P, m, k+1, j) + P[i-1] * P[k] * P[j]
4       if q < m[i, j] then m[i, j] = q
5   return m[i, j]

//Matrix Chain Multiplication: Bottom-Up DP (Non-Recursive)

MATRIXCHAINORDER(P, n)  // Array P has size n+1
1   Let m[1...n, 1...n] be a new table
2   for i = 1 to n
3       m[i, i] = 0  // Cost of multiplying a single matrix is 0
4   for l = 2 to n  // l is the chain length
5       for i = 1 to n - l + 1
6           j = i + l - 1
7           m[i, j] = ∞
8           for k = i to j - 1
9               q = m[i, k] + m[k+1, j] + P[i-1] * P[k] * P[j]
10              if q < m[i, j]
11                  m[i, j] = q
12  return m[1, n]   // Minimum cost of multiplying matrices


//
