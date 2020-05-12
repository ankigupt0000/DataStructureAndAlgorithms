CC = gcc
CFLAGS = -std=c99 -Wall -pedantic -O3 -g3
RM = rm -f
DEQUE = deque
MAIN_DEQUE = testDeque
RING_BUFFER = ringBuffer
MAIN_RB = testRingBuffer
MEM_CHECK_TOOL = valgrind
MEM_CHECK_FLAGS = -q --leak-check=yes

#how many iterations for test
ITERATIONS = 10000000
VALGRIND_ITERATIONS=100

all: $(MAIN_DEQUE) $(MAIN_RB)

test: all
	./$(MAIN_DEQUE) $(ITERATIONS)
	$(MEM_CHECK_TOOL) $(MEM_CHECK_FLAGS) ./$(MAIN_DEQUE) $(VALGRIND_ITERATIONS)
	./testRingBuffer $(ITERATIONS)
	$(MEM_CHECK_TOOL) $(MEM_CHECK_FLAGS) ./$(MAIN_RB) $(VALGRIND_ITERATIONS)
	
time:all
	time ./$(MAIN_DEQUE) $(ITERATIONS)
	time ./$(MAIN_RB) $(ITERATIONS)
	
testDeque: $(MAIN_DEQUE).o $(DEQUE).o
	$(CC) $(CFLAGS) -o $@ $^
	
testRingBuffer: $(MAIN_DEQUE).o $(RING_BUFFER).o
	$(CC) $(CFLAGS) -o $@ $^
	
clean:
	$(RM) $(MAIN_DEQUE) $(MAIN_RB) *.o
