FLAG= -std=c++17 -lstdc++fs -lmysqlcppconn
GCC=g++ -Wall
ALL=USB

USB : main.o usbReader.o sqlConnector.o
	$(GCC) -o USB main.o usbReader.o sqlConnector.o $(FLAG)

main.o : main.cpp
	$(GCC) -c main.cpp

sqlConnector.o : sqlConnector.cpp sqlConnector.hpp
	$(GCC) -c sqlConnector.cpp

usbReader.o : usbReader.cpp usbReader.hpp
	$(GCC) -c usbReader.cpp

clean :
	rm *.o
	rm $(ALL)
