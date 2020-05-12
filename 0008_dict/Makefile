CC = gcc
CFLAGS = -Wall -std=c99
PROG = dict
MAIN = testDict
OBJS = $(PROG).o

all: $(MAIN)

$(MAIN): $(OBJS) $(MAIN).o
	$(CC) $(CFLAGS) -o $@ $^	

$(MAIN).o: $(MAIN).c
	$(CC) $(CFLAGS) -c -o $@ $^	

$(OBJS): $(PROG).c
	$(CC) $(CFLAGS) -c -o $@ $^

clean:
	rm -f $(OBJS) $(MAIN).o $(MAIN)