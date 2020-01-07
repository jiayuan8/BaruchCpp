all:
	clang++ Point.cpp -c
	clang++ Shape.cpp -c
	clang++ PointArray.cpp -c
	clang++ test.cpp -c
	clang++ Shape.o Point.o PointArray.o test.o -o test.out
	rm -f *.o