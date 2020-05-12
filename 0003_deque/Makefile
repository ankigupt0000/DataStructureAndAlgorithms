CC = gcc
CFLAGS = -Wall -std=c99
PROG = deque
MAIN = testDeque
OBJS = $(PROG).o

$(MAIN): $(OBJS) $(MAIN).o
	$(CC) $(CFLAGS) -o $@ $^	

$(MAIN).o: $(MAIN).c
	$(CC) $(CFLAGS) -c -o $@ $^	

$(OBJS): $(PROG).c
	$(CC) $(CFLAGS) -c -o $@ $^

clean:
	rm -f $(OBJS) $(MAIN).o $(MAIN)
