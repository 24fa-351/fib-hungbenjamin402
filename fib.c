#include <stdio.h>

int main() {
    FILE *fpointer;
    int fibTerms = 0;
    int fibSeq[1000];

    int fibFirstTerm = 0;
    int fibSecTerm = 1;

    // Open the file
    fpointer = fopen("/Users/benj/Documents/Coding/fib-hungbenjamin402/fibTerms.txt","r");

    // Verify the opening file status
    if (fpointer == NULL) {
        printf("Error opening file\n");
        return -1;
    }

    // Read  fibonacci terms from file and store it in fibTerms
    fscanf(fpointer, "%d", &fibTerms);

    // Close the file
    fclose(fpointer);

    // Initiate first and second term in Fib Array
    fibSeq[0] = fibFirstTerm;
    fibSeq[1] = fibSecTerm;

    printf("Fibonacci Terms: %d\n", fibTerms);

    printf("Fib 1: %d\n", fibSeq[0]);
    printf("Fib 2: %d\n", fibSeq[1]);

    // Fibonacci Algo

    // Calculate the Fibonacci sequence
    for (int i = 2; i < fibTerms; i++) {
        fibSeq[i] = fibSeq[i-1] + fibSeq[i-2];
    }

    // Print the Fibonacci sequence
    for (int i = 0; i < fibTerms; i++) {
        printf("%d ", fibSeq[i]);
    }

    return 0;
}
