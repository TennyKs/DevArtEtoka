FLAG= -std=c++17 -lstdc++fs
GCC=g++ -Wall
ALL=USB

USB : main.o usbReader.o
	$(GCC) -o USB main.o usbReader.o $(FLAG)

main.o : main.cpp
	$(GCC) -c main.cpp

usbReader.o : usbReader.cpp usbReader.hpp
	$(GCC) -c usbReader.cpp

clean :
	rm *.o
	rm $(ALL)
