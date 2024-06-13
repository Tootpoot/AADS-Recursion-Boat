all: boats
boats: removal main.o Boat.o
				g++ -o boats main.o Boat.o
main.o: main.cpp
				g++ -c -g main.cpp
Boat.o: Boat.cpp
				g++ -c -g Boat.cpp
removal:
				rm -f *.o
