// TrigQuiz.hpp
// TrigQuiz mechanics and behind-the-scene working data.
//
// Author: Rohit Mehta
// --------------------------------------------------------------

#ifndef _TRIG_QUIZ_
#define _TRIG_QUIZ_

void init();

// Constructs the options with correct option index(in values) passed as args
// and, Prints them on the screen.
// Returns: the correct option no. (a, b, c, or d)
char getOpt(const int trig, const int angle);

//////////////////////////////////////////////////////////
//Start the main game and never exit until the game ends//
void startGame();

#endif // _TRIG_QUIZ_