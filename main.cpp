// main.cpp
// TrigQuiz -- A simple Trigonometry Game.
//
//Author: Rohit Mehta

#include "TrigQuiz.hpp"
// almost most of the needed headers file are included in this header
// so i'll not re-include them.

int main()
{
    init();     // initialize
    char c;
    do{
        startGame();
        cout << endl;
        cout << "Play again? [y/n] (default: y):   ";
        cin.get(c);
    }while(c != 'n' || c != 'N');

    return 0;
}