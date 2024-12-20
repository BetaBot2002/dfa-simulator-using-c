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
5. Define the transitions.

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
   ----- DFA Menu -----
   1. Create DFA
   2. Test String
   3. Exit
   --------------------
   Enter your choice: 1
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
   Enter Next State for Current State:0 and Input:a:
   1
   Enter Next State for Current State:0 and Input:b:
   0
   Enter Next State for Current State:1 and Input:a:
   1
   Enter Next State for Current State:1 and Input:b:
   2
   Enter Next State for Current State:2 and Input:a:
   2
   Enter Next State for Current State:2 and Input:b:
   2
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
   delta(Q0, a) -> Q1
   delta(Q1, b) -> Q2
   delta(Q2, b) -> Q2
   delta(Q2, a) -> Q2
   The string is accepted by the DFA.

   ----- DFA Menu -----
   1. Create DFA
   2. Test String
   3. Exit
   --------------------
   Enter your choice: 2
   Enter a string to test: bbb
   delta(Q0, b) -> Q0
   delta(Q0, b) -> Q0
   delta(Q0, b) -> Q0
   The string is rejected by the DFA.
   ```

---

## Code Structure

- **`dfa`**:  
  Struct representing the DFA, including states, input alphabet, transitions, starting state, and final states.

- **`transition`**:  
  Struct representing a single transition rule.

- **Functions**:  
  - `create_dfa()`: Creates a new DFA based on user input.  
  - `input_no_of_states()`: Inputs and validates the number of states.  
  - `input_no_of_input_alphabets()`: Inputs and validates the number of input alphabets.  
  - `input_input_alphabet()`: Inputs and validates the alphabet symbols.  
  - `input_starting_state()`: Inputs and validates the starting state.  
  - `input_no_of_final_states()`: Inputs and validates the number of final states.  
  - `input_final_states()`: Inputs and validates the final states.  
  - `input_transitions()`: Inputs and validates state transitions.  
  - `dfa_driver()`: Simulates the DFA for a given input string.  
  - `get_next_state()`: Fetches the next state for a given input and current state.  
  - `is_final_state()`: Checks if a given state is a final state.  
  - `create_transition()`: Allocates memory for a new transition.  
  - `display_menu()`: Shows the menu for user to operate.  
  - `free_dfa()`: Frees all dynamically allocated memory associated with the DFA, including transitions, input alphabet, and final states.  
  - `free_transition()`: Frees memory allocated for the transitions array of the DFA.  
---
## To contribute view [Contributing Guide](Contributing.md)