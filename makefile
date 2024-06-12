all: Boat
Boat: removal main.o Boat.o
    g++ -o Boat main.o Boat.o
main.o: main.cpp
    g++ -c -g Boat.cpp
Boat.o: Boat.cpp
    g++ -c -g Boat.cpp
removal: 
    rm -f *.o