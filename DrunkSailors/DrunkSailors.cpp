// DrunkSailors.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

constexpr auto MAX_WIDTH = 20;;
constexpr auto MAX_HEIGHT = 20;;
constexpr auto STEPS = 1000;;


using namespace std;

enum Directions{N= 0,E,S,W};

 Directions direct;

int main()
{
    //seed the random function
    srand(time(NULL));
    //create the board and zero it out
    int board[MAX_WIDTH][MAX_HEIGHT];

    //nested for loop zeros out the board
    for (int x = 0; x < MAX_WIDTH; x++) {
        for (int y = 0; y < MAX_HEIGHT; y++) {

            board[x][y] = 0;

        }
    }
    //record the position of object
    int X = MAX_WIDTH / 2;
    int Y = MAX_HEIGHT / 2;

    //record initial position
    board[X][Y]++;
   
    int direction; //variable for random enum number generator

    //movement loop for 1000 steps
    for (int steps = 0; steps < STEPS; steps++)
    {
        direction = rand() % 4;

        if (direction == N)
            Y--;
        if (direction == E)
            X++;
        if (direction == S)
            Y++;
        if (direction == W)
            X--;
        //to prevent from going out of bounds
        if (X > MAX_WIDTH - 1)
            X--;
        if (Y > MAX_HEIGHT - 1)
            Y--;
        if (X < 0)
            X++;
        if (Y < 0)
            Y++;
        //record movement

        board[X][Y] ++;
    }
    //print out 
    for (int x = 0; x < MAX_WIDTH; x++){
        for (int y = 0; y < MAX_HEIGHT; y++) {



            cout << board[x][y] << "; ";
        }
        cout << endl;
    }
        return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
