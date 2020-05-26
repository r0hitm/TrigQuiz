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