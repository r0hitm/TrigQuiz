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
#include <sstream>
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


inline  void init(){        // initialize
    srand( time(NULL) );
    cout << endl;
    cout << "*******************************************************\n"
            "**                     TRIG QUIZ                     **\n"
            "*******************************************************\n\n";

    cout << "Game Rules: You will be asked about the values of some\n"
            "----------  Trigonometric Functions at acute angle (at\n"
            "            0°,30°,45°,60°,90°). You will have four \n"
            "            options Choose any one.\n"
            "            ♦ Correct answers worth +4 Points\n"
            "            ♦ Incorrect answers worth -1 points\n\n";
}
// Constructs the options with correct option index(in values) passed as args
// and, Prints them on the screen.
// Returns: the correct option no. (a, b, c, or d)
static char getOpt(const int trig, const int angle)
{
    string opt[4];
    int    opt_i = 0;       // index into opt.
    
    // First fill all four options with multiple values
    // then place the correct value at any random place.
    while(opt_i < 4){
        int i = rand() % 6, j = rand() % 6;
        
        if ( i != trig && j != angle)
        {
            opt[opt_i] = values[i][j];
            opt_i++;            // now to next option
        }
    }

    // now placing correct option somewhere in the options
    char c = 'a' + rand() % 4;
    opt[int(c -'a')] = values[trig][angle];

    #ifdef DEBUG
        cout << "\n#DEBUG# (inside getOpt):  c = " << c << "\tint(c - 'a') = " << int(c - 'a') << endl;
        cout << "\n#DEBUG# (inside getOpt):  value[trig][angle]  = " << values[trig][angle]
             << "\t opt at c = " << opt[int(c - 'a')] << endl << endl;
    #endif

    // Print it !
    cout << setw(30) << left << "a) " + opt[0] << "b) " + opt[1] << endl;
    cout << setw(30) << left <<  "c) " + opt[2]  << "d) " + opt[3] << endl;
    cout << endl;

    return c;
}

//////////////////////////////////////////////////////////
//Start the main game and never exit until the game ends//
void startGame()
{
    cout << "Press Enter when Ready...";
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

        #ifdef DEBUG
            cout << "\n#DEBUG# (inside startGame()) : trig = " << trig << "\t angle = " << angle << endl << endl;
        #endif

        // constructing the question in parts using stringstream.
        stringstream question;
        question << "Q." << i << " ";

        switch(trig)
        {
            case 0: question << "sin("; break;
            case 1: question << "cos("; break;
            case 2: question << "tan("; break;
            case 3: question << "csc("; break;
            case 4: question << "sec("; break;
            case 5: question << "cot("; break;
            
            default: cerr << "Error: Invalid Trig Function.\n";
                    exit(1);
        }
        switch(angle)
        {
            case 0: question << "0"; break;
            case 1: question << "30"; break;
            case 2: question << "45"; break;
            case 3: question << "60"; break;
            case 4: question << "90"; break;

            default: cerr << "Error: Invalid Angle.\n";
                    exit(2);
        }
        question << "°) = ?\n";

        // get the question from the string stream and print it on screen
        cout << question.str() << flush;

        char correct = getOpt(trig, angle);     // Print options and get the correct option label.
        
        #ifdef DEBUG
            cout << "\n#DEBUG# (inside startGame()) : correct(Line 124) = " << correct << endl << endl;
        #endif

        char  usrInput = '\0';
        while(true)
        {
            cout << "Your Answer: ";

            if(! cin.getline(&usrInput, 2) ) {  // QUESTION: Why i've to place 2 as second arg? meaning that \n will also be read. usrInput is a char type variable.
                cerr << "Error occured while reading your Answer. X_X\n"
                      << "Check your Input" << endl;
                exit(3);
            }
            cin.sync();     // sync the input stream,
            cin.clear();    // and clear any error that may have occured.

            #ifdef DEBUG
                cout << "\n#DEBUG# (inside do-while): usrInput = " << usrInput << endl
                     << "isalpha(usrInput) = " << boolalpha << isalpha(usrInput) << endl;
            #endif

            if(isalpha(usrInput)){              // valid input ---> a character
                usrInput = tolower(usrInput);   // yes ---> into lowercase

                if( usrInput < 'a' || usrInput > 'd' )
                   cerr << "Input Error: What are you Typing man!\n";
                else
                    break;
            }else{
                cerr << "Invalid Input: Enter a, b, c or d.\n";
            }
            
            #ifdef DEBUG
                cout << "##After tolower(usrInput), usrInput = " << usrInput << endl << endl;
            #endif
        }

        if(usrInput == correct){  // Usr is correct
            usrScore += 4;        // increase score.
            cout << "---------------------\n"
                    "You are correct [+4] ^_^\n";
        }
        else{
            usrScore--;     // Usr is incorrect. Deduct score.
            cout << "-------------\n"
                    "Too Bad. Wrong[-1] T_T\n";
        }

        #ifdef SCR_DEBUG
        cout << "Current User SCore: " << usrScore << endl;
        #endif

        cout << endl << endl;
        i++;
    }
    
    cout << "\t\t* * * Game Over * * *\n";
    cout << "Your Score: " << usrScore << "/40\n";
}
#endif // _TRIG_QUIZ_