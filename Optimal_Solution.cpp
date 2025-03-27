//Algorithm: Print Optimal Parentheses

PRINTOPTIMALPARENS(s, i, j)
1   if i == j
2       print "A", i   // Print matrix name
3   else
4       print "("
5       PRINTOPTIMALPARENS(s, i, s[i, j])   // Recursively print left subproblem
6       PRINTOPTIMALPARENS(s, s[i, j] + 1, j)  // Recursively print right subproblem
7       print ")"


//
