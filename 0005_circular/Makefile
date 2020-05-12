CC = gcc
CFLAGS = -Wall -std=c99
PROG = circular
OBJS = $(PROG).o

$(OBJS): $(PROG).c
	$(CC) $(CFLAGS) -c -o $@ $^

clean:
	rm -f $(OBJS) $(MAIN).o $(MAIN)
