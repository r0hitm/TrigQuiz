// main.cpp
// TrigQuiz -- A simple Trigonometry Game.
//
//Author: Rohit Mehta

#include <iostream>
#include <iomanip>
using namespace std;

#include "TrigQuiz.hpp"

int main()
{
    init();     // initialize
    char c;
    while(true)
    {
        startGame();
        cout << endl;
        
        cout << "Play Again? [y/n]........... ";
        cin >> setw(2) >> c; cin.ignore();
        
        if( c == 'n' || c == 'N')
            break;
        else
        if( c == 'y' || c == 'Y')
            continue;
        else{
            cerr << "Can't you type a single character correctly !?\n"
                    "EXiting.....You LOSE X_X\n";
            exit(4);
        }
    }

    return 0;
}