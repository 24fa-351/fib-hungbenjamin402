#include <stdio.h>
#include <stdlib.h>  // For atoi()

// Recursive Fibonacci function
int fib_recursive(int n) {
    if (n == 1) return 0; // Fibonacci #1 is 0
    if (n == 2) return 1; // Fibonacci #2 is 1
    return fib_recursive(n - 1) + fib_recursive(n - 2);
}

// Iterative Fibonacci function
int fib_iterative(int n) {
    if (n == 1) return 0; // Fibonacci #1 is 0
    if (n == 2) return 1; // Fibonacci #2 is 1

    int fibFirstTerm = 0;
    int fibSecTerm = 1;
    int fibNthTerm = 0;

    for (int i = 3; i <= n; i++) {
        fibNthTerm = fibFirstTerm + fibSecTerm;
        fibFirstTerm = fibSecTerm;
        fibSecTerm = fibNthTerm;
    }

    return fibSecTerm;
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <integer> <r/i> <filename>\n", argv[0]);
        return 1;
    }

    // Parse command-line arguments
    int userInteger = atoi(argv[1]);
    char method = argv[2][0];
    char *filename = argv[3];

    // Read integer from the file
    FILE *fpointer = fopen(filename, "r");
    if (fpointer == NULL) {
        printf("Error opening file\n");
        return -1;
    }

    int fileInteger = 0;
    fscanf(fpointer, "%d", &fileInteger);
    fclose(fpointer);

    // Sum the user's integer and the file integer
    int N = userInteger + fileInteger;

    // Calculate Fibonacci using specified method
    int result;
    if (method == 'i') {
        result = fib_iterative(N);
    } else if (method == 'r') {
        result = fib_recursive(N);
    } else {
        printf("Invalid method. Use 'r' for recursive or 'i' for iterative.\n");
        return 1;
    }

    // Output the result with the required format: Fibonacci #N is result
    printf("%d", result);

    return 0;
}