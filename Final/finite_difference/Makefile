all:
	clang++ -std=c++11 Array.cpp -c
	clang++ -std=c++11 ArrayMechanisms.cpp -c
	clang++ -std=c++11 ArrayStructure.cpp -c
	clang++ -std=c++11 FullArray.cpp -c
	clang++ -std=c++11 Vector.cpp -c
	clang++ -std=c++11 TestBSPDE1.cpp -c
	clang++ -std=c++11 Array.o ArrayMechanisms.o ArrayStructure.o FullArray.o Vector.o TestBSPDE1.o -o test.out
	rm -f *.o