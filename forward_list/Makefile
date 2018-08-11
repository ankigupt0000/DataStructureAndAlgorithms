# for windows
# mingw32-make --makefile=makefile --directory="D:\DataStructures\forward_list" clean
# mingw32-make --makefile=makefile --directory="D:\DataStructures\forward_list"
# D:\DataStructures\forward_list\forwardlist_test
forwardlist_test: main_test.o forward_list.o
	gcc -o $@ $?
main_test.o: main_test.c 
	gcc -o $@ -c $<
forward_list.o: forward_list.c
	gcc -o $@ -c $<
clean:
	rm forwardlist_test forward_list.o main_test.o
