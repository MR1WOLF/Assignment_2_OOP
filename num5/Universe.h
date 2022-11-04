#ifndef UNIVERSE_H
#define UNIVERSE_H
#include <iostream>
#include <array>

const int SIZE1 = 20;
const int SIZE2 = 20;

using namespace std;

class Universe{
    private:
        array<array<int, SIZE1>, SIZE2> board;
        int NumberofGen;
    public:
        Universe(int num, bool randomize);
        void reset();
        int count_neighbors(int x, int y);
        void next_generation();
        void display();
        void run();
};



#endif