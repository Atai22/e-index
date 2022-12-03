CC = g++
CPPFLAGS = -g -pedantic -Wall -Wextra -O2

all: el_index

el_index: main.o class.o
		$(CC) $(CPPFLAGS) main.o class.o -o el_index

main.o: main.cpp class.hpp
		$(CC) $(CPPFLAGS) -c main.cpp -o main.o

class.o: class.cpp class.hpp
		$(CC) $(CPPFLAGS) -c class.cpp -o class.o

clean:
		rm *.o el_index
run:
		make
		./el_index
