#include <stdio.h>
#include <stdlib.h>  // For atoi()

// Recursive Fibonacci function
int fib_recursive(int n) {
    // Base cases
    if (n <= 0) return 0;  // Handle non-positive inputs
    if (n == 1 || n == 2) return 1;  // F(1) = F(2) = 1

    // Recursive case: F(n) = F(n-1) + F(n-2)
    return fib_recursive(n - 1) + fib_recursive(n - 2);
}

// Iterative Fibonacci function
int fib_iterative(int n) {
    // Handle edge cases
    if (n <= 0) return 0;  // Handle non-positive inputs
    if (n == 1 || n == 2) return 1;  // F(1) = F(2) = 1

    int fib_prev = 1;       // F(n-1)
    int fib_prev_prev = 1;  // F(n-2)
    int fib_current = 2;    // F(n)

    // Calculate Fibonacci numbers iteratively
    for (int i = 3; i < n; i++) {
        fib_prev_prev = fib_prev;
        fib_prev = fib_current;
        fib_current = fib_prev + fib_prev_prev;
    }

    return fib_current;
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

    printf("Calculating the Fibonacci number for N = %d...\n", N);

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
    printf("Fibonacci #%d is %d\n", N, result);

    return 0;
}