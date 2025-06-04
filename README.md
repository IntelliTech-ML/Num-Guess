# 🎮 Guess the Number Game 🎯

---

## About This Game

Welcome to "Guess the Number," a classic and engaging game reimagined with a user-friendly graphical interface! Developed in **C language** and leveraging the powerful **Windows.h API**, this game provides an intuitive and interactive experience for players of all ages. Your primary objective is to deduce a randomly selected secret number within a specified range. But it's not just about guessing; our sophisticated scoring system and integrated hint mechanism add layers of strategy and excitement, making every round a unique challenge.

---

## ✨ Core Features

This game comes packed with features designed to enhance your gameplay and keep you entertained:

* **Dynamic User Interface:** Crafted with the **Windows.h API**, the game boasts a clean and responsive interface, ensuring a smooth and enjoyable user experience. All controls are clearly laid out for easy navigation.
* **Intelligent Random Number Generation:** At the start of each game, a new secret number (between 1 and 10) is pseudo-randomly generated using `srand(time(0))` and `rand() % 10 + 1`. This ensures unpredictability and replayability for endless fun.
* **Intuitive Input and Feedback:** Players can simply type their guess into the dedicated **input box**. Upon clicking the **"Guess" button**, immediate feedback is provided, indicating whether your guess was **"Too high!"**, **"Too low!"**, or **"Congratulations!"**
* **Strategic Hint System:** Stuck on a number? The **"Hint" button** (which appears after your second attempt) offers helpful clues related to the secret number. These hints, defined in a `Hint` struct array, are designed to guide your deductions without giving away the answer directly. For example, guessing "1" might yield the hint "The Topper," while "6" might be "Hardly Comes in Dice."
* **Rewarding Point System:** The game incorporates a nuanced scoring mechanism that rewards efficiency and penalizes excessive attempts.
    * **Higher points** are awarded for guessing the number in fewer attempts.
    * **Points are deducted** if the correct number is not found within the maximum allowed tries.
    * Your **total points** are tracked and displayed, encouraging players to improve their guessing strategy.
* **Instant Game Reset:** A **"Restart" button** (which appears once the game is won or lost) allows for quick replays, enabling players to immediately jump into a new round without restarting the application.
* **Adaptive Control Visibility:** Certain game elements, like the **Hint** and **Restart** buttons, dynamically appear or hide based on the game's state, providing a clutter-free interface and guiding the player through the current stage of the game.

---

## 🕹️ How to Play

Playing "Guess the Number" is straightforward and engaging:

1.  **Start the Game:** Upon launching the application, you'll be greeted with a message: "I have chosen a number between 1 and 10. Can you guess it?"
2.  **Enter Your Guess:** Locate the input box and type in your numerical guess (a whole number between 1 and 10).
3.  **Submit Your Guess:** Click the **"Guess" button**. The game will then provide instant feedback in the message area below the buttons.
4.  **Utilize Hints (Optional):** After your second attempt, the **"Hint" button** will become visible. If you're struggling, click it to receive a clue about the secret number.
5.  **Monitor Your Progress:** The game continuously updates your **"Total Points"** display, so you can track your overall score.
6.  **Restart the Game:** Once you either guess the correct number or exhaust your attempts, the **"Restart" button** will appear. Click it to begin a brand new game with a fresh secret number and reset your attempt count.

---

## 📊 Comprehensive Scoring System

Your performance in "Guess the Number" is precisely measured by how efficiently you can pinpoint the correct number. The scoring system is designed to reward strategic thinking and quick deductions:

* **For Successful Guesses:**
    * **1st Attempt:** An impressive **10 points!**
    * **2nd Attempt:** A strong **8 points.**
    * **3rd Attempt:** A solid **6 points.**
    * **4th Attempt:** A decent **4 points.**
    * **5th Attempt:** A respectable **2 points.**

* **For Unsuccessful Guesses (After 5 Attempts):**
    * If you fail to guess the correct number within 5 attempts, a penalty of **-2 points** is applied to your total score. The game will reveal the correct number, and the "Guess" button will be disabled, prompting you to "Restart."

This detailed scoring system adds an exciting competitive edge, encouraging players to refine their strategies and aim for those high-scoring, early guesses!

---

## 🚀 Installation & Setup

To enjoy "Guess the Number" on your Windows machine, follow these straightforward steps:

1.  **Prerequisites:** Ensure you have a C compiler installed on your system. **GCC** (GNU Compiler Collection), often included with MinGW or Cygwin on Windows, is highly recommended.
2.  **Clone the Repository:** Open your command prompt or Git Bash and clone the game's repository to your local machine:
    ```bash
    git clone [https://github.com/yourusername/guess-the-number-game.git](https://github.com/yourusername/guess-the-number-game.git)
    ```
    (Note: Replace `yourusername` with the actual GitHub username if you're cloning from a specific fork.)
3.  **Navigate to the Game Directory:** Change your current directory to the newly cloned game folder:
    ```bash
    cd guess-the-number-game
    ```
4.  **Compile the Source Code:** Compile the `main.c` file using GCC. The `-o` flag specifies the output executable name:
    ```bash
    gcc main.c -o guess_the_number
    ```
    This command will create an executable file named `guess_the_number.exe` (or simply `guess_the_number` on Linux/macOS, though this game is Windows-specific due to `windows.h`).
5.  **Run the Game:** Execute the compiled program:
    ```bash
    ./guess_the_number
    ```
    The "Guess the Number Game" window will appear, ready for you to start playing!

---

## ✍️ Author

* **Ajay Soni** - Initial development and core implementation.

---

## 🤝 Contributing

We welcome contributions from the community! If you have ideas for improvements, bug fixes, or new features, feel free to:

1.  **Fork** the repository.
2.  **Create a new branch** for your changes.
3.  **Commit** your changes with clear, descriptive messages.
4.  **Push** your branch to your fork.
5.  **Submit a Pull Request** to the `main` branch of this repository.

Please ensure your code adheres to good coding practices and includes relevant comments.

---

## 📄 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

---
