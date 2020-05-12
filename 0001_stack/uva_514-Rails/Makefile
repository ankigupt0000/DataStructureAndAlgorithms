CC = gcc
CFLAGS = -Wall -std=c99
MAIN = rails
OBJS = stack.o
OTHER = rails_plus_stack


$(MAIN): ../$(OBJS) $(MAIN).o
	$(CC) $(CFLAGS) -o $@ $^

$(MAIN).o: $(MAIN).c
	$(CC) $(CFLAGS) -c -o $@ $^

$(OTHER): $(OTHER).o
	$(CC) $(CFLAGS) -o $@ $^

$(OTHER).o: $(OTHER).c
	$(CC) $(CFLAGS) -c -o $@ $^


clean:
	rm -f  $(MAIN).o $(MAIN) $(OTHER) $(OTHER).o
