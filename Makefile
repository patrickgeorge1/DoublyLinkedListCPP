build:
	g++ doubly-linked.cpp -o a.out
	./a.out

valgrind:
	g++ doubly-linked.cpp -o a.out
	valgrind --leak-check=yes ./a.out

debug:
	g++ -g doubly-linked.cpp -o a.out

remove:
	rm a.out
