CC = g++
CFLAGS = -Wall -Wextra -I .

 all:
	$(CC) $(CFLAGS) -c main.cpp deque.cpp
	$(CC) $(CFLAGS) -o deque main.o deque.o