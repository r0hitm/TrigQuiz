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
    string     opt[4];          // four options

    // As the values of trig functions are repetitive in nature the following array is use to construct a options list
    // that doesn't contain the repetitive choices
    string    temp[11] = {"0", "1/2", "1/√2", "√3/2", "√3", "1/√3", "1", "undefined", "2/√3", "√2", "2"};
    string    right              = values[trig][angle];      // get the right value

    // First fill all four options with multiple values
    // then place the correct value at any random place.
    for(int i = 0; i < 4; )
    {
        // get a index location into forwrongValues[]
        // then remove this position so that it never repeats
        int tmp = rand() % 11;

        if( temp[tmp] != "" && temp[tmp] != right ){
            opt[i] = temp[tmp];
            temp[tmp] = "";
            i++;
        }
    }

    // now placing correct option somewhere in the options
    char c = 'a' + rand() % 4;
    opt[int(c -'a')] = right;

    // Print it !
    cout << setw(30) << setfill(' ') << left << "a) " + opt[0] << "b) " + opt[1] << endl;
    cout << setw(30) << setfill(' ') << left << "c) " + opt[2] << "d) " + opt[3] << endl;
    cout << endl;

    return c;
}

//////////////////////////////////////////////////////////
//Start the main game and never exit until the game ends//
void startGame()
{
    cout << "Press Enter when Ready...";
    cin.get(); cin.clear(); cin.sync();     // clear and sync the input stream

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

        // Print the Question in-parts
        cout << "Q." << i << " ";       // Question no. first

        switch(trig)
        {           // then Trig Funcion
            case 0: cout << "sin("; break;
            case 1: cout << "cos("; break;
            case 2: cout << "tan("; break;
            case 3: cout << "csc("; break;
            case 4: cout << "sec("; break;
            case 5: cout << "cot("; break;
            
            default: cerr << "Error: Invalid Trig Function.\n";
                    exit(1);
        }
        switch(angle)
        {       /// and finally the angle(at which trig is to be evaluted)
            case 0: cout << "0"; break;
            case 1: cout << "30"; break;
            case 2: cout << "45"; break;
            case 3: cout << "60"; break;
            case 4: cout << "90"; break;

            default: cerr << "Error: Invalid Angle.\n";
                    exit(2);
        }
        cout << "°) = ?\n";

        // Print options and get the correct option label.
        char correct = getOpt(trig, angle);

        char  usrInput = '\0';
        while(true)
        {
            cout << "♥ You Choose: ";

            /* if(! cin.getline(&usrInput, 2) ) {
                // QUESTION: Why i've to place 2 as second arg? meaning that \n will also be read. usrInput is a char type variable.


                cerr << "That is not a valid Option.\n"
                      << "Check your Input...Well Never Mind. You are *disqualified*." << endl;
                exit(3);
            } */
            // is the above commented-out block is changing the value of correct.?
            //---> cin.getline(&usrInput, 2); <-- yes, after this line the value of correct goes to 0 '\000'. But, why?

            cin >> usrInput;
            cin.sync();     // sync the input stream,
            cin.clear();    // and clear any error that may have occured.

            if(isalpha(usrInput)){              // valid input ---> a character
                usrInput = tolower(usrInput);   // yes ---> into lowercase

                if(usrInput == 'q')
                    cout << "You are Quitting already?!\n",
                    exit(EXIT_SUCCESS);

                if( usrInput < 'a' || usrInput > 'd' )
                   cerr << "Input Error: What are you Typing man!\n";

                else
                    break;

            }else{
                cerr << "Invalid Input: Enter a, b, c or d.\n";
            }
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

        cout << endl << endl;
        i++;
    }
    
    cout << "\t\t* * * Game Over * * *\n";
    cout << "Your Score: " << usrScore << "/40\n";
    cout << "Accuracy:    " << fixed << setprecision(2) << float(usrScore * 100 / 40) << " %\n";
}
#endif // _TRIG_QUIZ_