# DFA Simulator

A simple C program to simulate a Deterministic Finite Automaton (DFA). The program allows users to define a DFA and test if a given input string is accepted by the DFA.

## Features
- Define a DFA by specifying:
  - Number of states.
  - Input alphabet.
  - Starting state.
  - Final states.
  - Transition rules.
- Test if an input string is accepted or rejected by the DFA.
- Menu-driven interface.

---

## How to Compile and Run

### Prerequisites
- GCC Compiler

### Steps to Compile
> ⚠️ Create a folder named 'build' in root

```bash
gcc src/main.c -o build/main
```

### Steps to Run
```bash
./build/main
```

---

## Menu Options

1. **Create DFA**:  
   Define a new DFA by specifying its states, input alphabet, transitions, starting state, and final states.

2. **Test String**:  
   Provide a string as input to check if it is accepted by the DFA.

3. **Exit**:  
   Exit the program.

---

## Input Format

### DFA Creation
1. Enter the number of states.
2. Enter the size of the input alphabet, followed by each symbol.
3. Enter the starting state.
4. Enter the number of final states, followed by each final state.
5. Define the transitions in the format:  
   ```
   current_state input next_state
   ```

### Test String
- Input the string to be tested (sequence of characters from the input alphabet).

---

## Example Usage

### Sample Menu Interaction
1. **Menu Option**:  
   ```
   ----- DFA Menu -----
   1. Create DFA
   2. Test String
   3. Exit
   --------------------
   Enter your choice: 1
   ```

2. **Create DFA**:  
   ```
   Enter no. of states:
   3
   Enter no. of input alphabets:
   2
   Enter symbol 1:
   a
   Enter symbol 2:
   b
   Enter starting state (0 to 2):
   0
   Enter no. of final states:
   1
   Enter final state 1:
   2
   Enter transition 1 (current_state input next_state):
   0 a 1
   Enter transition 2 (current_state input next_state):
   0 b 0
   Enter transition 3 (current_state input next_state):
   1 a 1
   Enter transition 4 (current_state input next_state):
   1 b 2
   Enter transition 5 (current_state input next_state):
   2 a 2
   Enter transition 6 (current_state input next_state):
   2 b 2
   DFA created successfully!
   ```

3. **Test String**:  
   ```
   ----- DFA Menu -----
   1. Create DFA
   2. Test String
   3. Exit
   --------------------
   Enter your choice: 2
   Enter a string to test: abba
   The string is accepted by the DFA.
   ```

---

## Code Structure

- **`dfa`**:  
  Struct representing the DFA, including states, input alphabet, transitions, starting state, and final states.

- **`transition`**:  
  Struct representing a single transition rule.

- **Functions**:
  - `create_dfa()`: Creates a new DFA based on user input.
  - `dfa_driver()`: Simulates the DFA for a given input string.
  - `get_next_state()`: Fetches the next state for a given input and current state.
  - `is_final_state()`: Checks if a given state is a final state.
  - `create_transition()`: Allocates memory for a new transition.
---
## To contribute view [Contributing Guide](Contributing.md)