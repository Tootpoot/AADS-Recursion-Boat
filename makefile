g++ -c Boat.cpp -o Boat.o
g++ -c main.cpp -o main.o
g++ Boat.o main.o -o main
./main
