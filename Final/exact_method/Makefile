all:
	clang++ -std=c++11 options.cpp -c
	clang++ -std=c++11 American.cpp -c
	clang++ -std=c++11 European.cpp -c
	clang++ -std=c++11 utils.cpp -c
	clang++ -std=c++11 main.cpp -c
	clang++ -std=c++11 options.o American.o European.o utils.o main.o -o test.out
	rm -f *.o