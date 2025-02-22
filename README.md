# Guess the Number Game

**About**

A "Guess the Number" game implemented using C language with an intuitive user interface and the Windows.h window API. Players try to guess a randomly selected number within a specified range.

**Features**

- Start Again button for quick replays
- Hint button to assist with educated guesses
- Point system that rewards players for fewer attempts and penalizes for multiple failed attempts

**Gameplay**

1. Enter your guess in the input box.
2. Click the Guess button to see if your guess is correct.
3. Use the Hint button for clues if you're stuck.
4. Click the Restart button to start a new game.

**Scoring**

- Players earn points based on the number of attempts taken to guess the correct number.
  - 1st attempt: 10 points
  - 2nd attempt: 8 points
  - 3rd attempt: 6 points
  - 4th attempt: 4 points
  - 5th attempt: 2 points
- If the correct number is not guessed within 5 attempts: -2 points

**Installation**

To play the game, clone the repository and compile the C code using your preferred compiler.

1. `git clone https://github.com/yourusername/guess-the-number-game.git`
2. `cd guess-the-number-game`
3. `gcc main.c -o guess_the_number`
4. `./guess_the_number`
