// TrigQuiz.hpp
// TrigQuiz mechanics and behind-the-scene working data.
//
// Author: Rohit Mehta
// --------------------------------------------------------------

#ifndef _TRIG_QUIZ_
#define _TRIG_QUIZ_

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <cctype>
using namespace std;


const string    values[6][5] =      // Values of some trigonometric angles.
{   //    \         0               30             45           60           90     : Angles in Sexasimal Units(degree)
    { /* sin */    "0",           "1/2",         "1/√2",       "√3/2",       "1" },
    { /* cos */    "1",           "√3/2",        "1/√2",       "1/2",        "0" },
    { /* tan */    "0",           "1/√3",         "1",         "√3",         "undefined"},
    { /* csc */    "undefined",     "2",          "√2",        "2/√3",       "1" },
    { /* sec */    "1",             "2/√3",       "√2",         "2",         "undefined"},
    { /* cot */    "undefined",     "√3",          "1",          "1/√3",     "0"}
};

const string banner =
"*******************************************************\n"
"**                     TRIG QUIZ                     **\n"
"*******************************************************\n";

const string rules = "\nI will ask you 10 questions regarding Trigonometry.\nTell me the value of"
" the trigonometric value of the angles 0°, 30°, 45°, 60° and 90°.\n"
"You will have four Multiple choices to choose from, "
"for each correct answer 4 will be awarded and for each incorrect answer 1 is deducted.";

inline  void init(){        // initialize
    srand( time(NULL) );
    cout << banner << endl;
    cout << rules << endl << endl;

    cout << "\t* * * Game Starts * * *\n";
}
// Constructs the options with correct option index(in values) passed as args
// and, Prints them on the screen.
// Returns: the correct option no. (a, b, c, or d)
static char getOpt(const int corr1, const int corr2)
{
    string opt[4];
    for(int i=0; i < 4; i++){           // First fill all options with wrong options
        int usrInput1 = rand() % 6, usrInput2 = rand() % 6;
        
        if ( usrInput1 != corr1 && usrInput2 != corr2)
            opt[i] = values[usrInput1][usrInput2];
    }

    // now placing correct option somewhere in the options
    char c = 'a' + rand() % 4;
    opt[int(c-'a')] = values[corr1][corr1];

    // Print it !
    cout << "\t    a) " + opt[0] << setw(10) << right << "b) " + opt[1] << endl;
    cout << "\t    c) " + opt[2] << setw(10) << right << "d) " + opt[3] << endl;
    cout << endl;

    return c;
}

//////////////////////////////////////////////////////////
//Start the main game and never exit until the game ends//
void startGame()
{
    cout << "Ready...? ";
    cin.get();

    int  usrScore = 0;

    // Generate a question.
    // Trig Function number mapping:
    // 0 = sin;     1 = cos; ... 5 = cot
    // Angle mapping:
    // 0 = 0°; 1 = 30°; ... 4 = 90°

    int i = 1;          // current question number.
    while(i <= 10)
    {
        unsigned trig = rand() % 6; unsigned angle = rand() % 5;

        string question = "\tQ." + char(i);
        switch(trig)
        {
            case 0: question += "  sin("; break;
            case 1: question += "  cos("; break;
            case 2: question += "  tan("; break;
            case 3: question += "  csc("; break;
            case 4: question += "  sec("; break;
            case 5: question += "  cot("; break;
            
            default: cerr << "Error: Invalid Trig Function.\n";
                    exit(1);
        }
        switch(angle)
        {
            case 0: question += "0"; break;
            case 1: question += "30"; break;
            case 2: question += "45"; break;
            case 3: question += "60"; break;
            case 4: question += "90"; break;

            default: cerr << "Error: Invalid Angle.\n";
                    exit(2);
        }
        question += "°) = ?\n";

        cout << question << flush;
        char correct = getOpt(trig, angle);     // Print options and get the correct option label.
        char  usrInput;
        do{
            cout << "Your Answer: ";
            cin.get(usrInput);          // get a single character.
            if(cin.bad()){
                cerr << "Error occured while reading your input.\nEnter valid input twit.\n";
                cerr << "You Lose ! :(\n";
                exit(3);
            }
            if( isalpha(usrInput) )
                tolower(usrInput);
            else
                cerr << "Input Error: What are you Typing man!\n"
                        "Enter a, b, c or d as per your correct option.\n";
        }
        while( usrInput != 'a' || usrInput != 'b' || usrInput != 'c' || usrInput != 'd');

        if(usrInput == correct){  // Usr is correct
            usrScore += 4;        // increase score.
            cout << "That was correct :)\n";
        }
        else{
            usrScore--;     // Usr is incorrect. Deduct score.
            cout << "Too Bad :(\n";
        }

        cout << endl << endl;
        i++;
    }
    
    cout << "\t\t* * * Game Over * * *";
    cout << "Your Score: " << usrScore << "/40\n";
}
#endif // _TRIG_QUIZ_