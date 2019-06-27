FLAG= -std=c++17 -lstdc++fs
GCC=g++ -Wall
ALL=idx

idx : index.o
	$(GCC) -o idx index.o $(FLAG)

index.o : index.cpp
	$(GCC) -c index.cpp

clean :
	rm *.o
	rm $(ALL)
