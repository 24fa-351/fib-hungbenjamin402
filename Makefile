CC = gcc
CFLAGS = -Wall -Wextra -g

# Compile the program
fib: fib.c
	$(CC) $(CFLAGS) -o fib fib.c

# Run tests
test: fib
	./fib 5 i fibTerms.txt > result_iter.txt
	diff result_iter.txt expected_iter.txt

	./fib 5 r fibTerms.txt > result_recur.txt
	diff result_recur.txt expected_recur.txt

clean:
	rm -f fib result_iter.txt result_recur.txt
