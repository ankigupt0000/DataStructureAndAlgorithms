CC = gcc
CFLAGS = -Wall -std=c99
PROG = treap
OBJS = $(PROG).o

all: $(PROG)

$(PROG): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJS): $(PROG).c
	$(CC) $(CFLAGS) -c -o $@ $^

clean:
	$(RM) -f $(PROG) $(OBJS)