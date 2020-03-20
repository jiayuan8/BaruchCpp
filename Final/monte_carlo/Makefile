all:
	clang++ -std=c++11 NormalGenerator.cpp -c
	clang++ -std=c++11 Range.cpp -c
	clang++ -std=c++11 TestMC.cpp -c
	clang++ -std=c++11 NormalGenerator.o Range.o TestMC.o -o test.out
	rm -f *.o