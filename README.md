# TrigQuiz

A Simple command line Trigonometry Multiple Choice Quiz Game.

## How to Build & Run

On *nix systems using g++ compiler, or using Cygwin on WSL on Windows:

```sh
g++ -Wall -o TrigQuiz TrigQuiz.cpp main.cpp
```

To Run, now type on *nix terminal:

```sh
./TrigQuiz
```

To run on windows, do this instead:

```bat
chcp 65001
TrigQuiz
```

__Note__: `chcp 65001` is required to make sure all characters are rendered properly on windows terminal.
