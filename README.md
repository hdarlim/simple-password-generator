# Simple Password Generator

A robust Command Line Interface (CLI) tool developed in **C** to generate secure, randomized passwords. This project was built to practice fundamental programming concepts, including array manipulation, control flow with `switch` statements, and algorithmic logic.
## 🚀 Features
- **Security Requirements**: Every generated password is guaranteed to contain:
    - At least one **uppercase** letter.
    - At least one **lowercase** letter.
    - At least one **digit** (0-9).
    - At least one **special symbol**.
- **Length Validation**: The program ensures a minimum length of 8 characters to follow modern security standards.
- **True Randomization**: Uses the system clock (`time.h`) as a seed for `srand()` to ensure a unique password every time the program runs.
- **Memory Efficiency**: Developed using stack-allocated arrays (VLAs), avoiding the complexity of dynamic memory allocation for this specific scope.

## 🧠 How it Works

The generation process follows a three-step logic to maintain both security and randomness:
1. **Guaranteed Base**: The first four positions of the password array are manually assigned one character from each required category (Upper, Lower, Number, Symbol).
2. **Random Fill**: A `for` loop completes the remaining length. Inside the loop, a `switch` statement uses `rand() % 4` to decide which character pool to draw from, ensuring an even distribution of character types.
3. **The Modulo Operator**: To map the large integers from `rand()` to valid array indices, the program uses the modulo operator (*index = rand() % pool_size*), ensuring memory safety.

## 🛠️ Requirements & Compilation

To compile and run this project, you need a C compiler (like `gcc` or `clang`).

Steps:
1. Clone the repository:

    `git clone https://github.com/hdarlim/simple-password-generator.git`

2. **Navigate to the folder**:

    `cd simple-password-generator`

3. **Compile the source code**:

    `gcc main.c -o password_gen`

4. **Run the executable**:

    `./password_gen`