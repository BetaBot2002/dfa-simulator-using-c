#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<ctype.h>

typedef struct transition{
    int current_state;
    char current_input;
    int next_state;
} transition;

typedef struct dfa{
    int no_of_states;
    char* input_alphabet;
    transition** transitions;
    int starting_state;
    int* final_states;
    int no_of_final_states;
    int no_of_input_alphabets;
} dfa;

int get_next_state(dfa* dfa,int current_input,int current_state){
    int no_of_transitions=dfa->no_of_input_alphabets*dfa->no_of_states;
    for(int i=0;i<no_of_transitions;i++){
        if(current_state==dfa->transitions[i]->current_state && 
            current_input==dfa->transitions[i]->current_input) return dfa->transitions[i]->next_state;
    }
    return -1;
}

bool is_final_state(dfa* dfa,int current_state){
    for(int i=0;i<dfa->no_of_final_states;i++){
        if(current_state==dfa->final_states[i]) return true;
    }
    return false;
}

bool dfa_driver(dfa* dfa,char* input,int current_state){
    if(*input=='\0'){
        return is_final_state(dfa,current_state);
    }
    int current_input=*input;
    int next_state=get_next_state(dfa,current_input,current_state);
    printf("delta(Q%d, %c) -> Q%d\n", current_state, current_input, next_state);
    return next_state>=0 && next_state<dfa->no_of_states ? dfa_driver(dfa,++input,next_state) : false;
}

transition* create_transition(int current_state,int current_input,int next_state){
    transition* new_transition=(transition*) malloc(sizeof(transition));
    new_transition->current_state=current_state;
    new_transition->current_input=current_input;
    new_transition->next_state=next_state;
    return new_transition;
}

void free_transition(transition** transitions,int no_of_transitions){
    for (int i = 0; i < no_of_transitions; i++){
        if(transitions[i]) (transitions[i]);
    }
    free(transitions);
}

void free_dfa(dfa* new_dfa){
    if (new_dfa->transitions) {
        int no_of_transitions=new_dfa->no_of_states * new_dfa->no_of_input_alphabets;
        free_transition(new_dfa->transitions, no_of_transitions);
    }
    if (new_dfa->input_alphabet) {
        free(new_dfa->input_alphabet);
    }
    if (new_dfa->final_states) {
        free(new_dfa->final_states);
    }
    free(new_dfa);
}

bool input_no_of_states(dfa* new_dfa){
    int no_of_states;
    printf("Enter no. of states:\n");
    scanf("%d", &no_of_states);
    if (no_of_states <= 0) return false;
    new_dfa->no_of_states = no_of_states;
    return true;
}

bool input_no_of_input_alphabets(dfa* new_dfa){
    int no_of_input_alphabets;
    printf("Enter no. of input alphabets:\n");
    scanf("%d", &no_of_input_alphabets);
    if (no_of_input_alphabets <= 0) return false;
    new_dfa->no_of_input_alphabets = no_of_input_alphabets;
    return true;
}

bool input_input_alphabet(dfa* new_dfa){
    for (int i = 0; i < new_dfa->no_of_input_alphabets; i++) {
        char temp;
        printf("Enter symbol %d:\n", i + 1);
        scanf(" %c", &temp);
        if(!isalnum(temp)) return false;
        new_dfa->input_alphabet[i]=temp;
    }
    return true;
}

bool input_starting_state(dfa* new_dfa){
    int starting_state;
    printf("Enter starting state (Q0 to Q%d):\nQ", new_dfa->no_of_states - 1);
    scanf("%d", &starting_state);
    if (starting_state < 0 || starting_state >= new_dfa->no_of_states) return false;
    new_dfa->starting_state=starting_state;
    return true;
}

bool input_no_of_final_states(dfa* new_dfa){
    int no_of_final_states;
    printf("Enter no. of final states:\n");
    scanf("%d", &no_of_final_states);
    if (no_of_final_states <= 0) return false;
    new_dfa->no_of_final_states = no_of_final_states;
    return true;
}

bool input_final_states(dfa* new_dfa){
    for (int i = 0; i < new_dfa->no_of_final_states; i++) {
        printf("Enter final state %d:\n", i + 1);
        scanf("%d", &new_dfa->final_states[i]);
        if (new_dfa->final_states[i] < 0 || new_dfa->final_states[i] >= new_dfa->no_of_states) {
            return false;
        }
    }
    return true;
}

bool input_transitions(dfa* new_dfa){
    for(int i=0;i<new_dfa->no_of_states;i++){
        int current_state=i;
        for(int j=0;j<new_dfa->no_of_input_alphabets;j++){
            new_dfa->transitions[i*new_dfa->no_of_input_alphabets+j]=NULL;
            char current_input=new_dfa->input_alphabet[j];
            int next_state;
            printf("Enter Next State for Current State:%d and Input:%c:\n", current_state,current_input);
            scanf("%d", &next_state);
            if (next_state < 0 || next_state >= new_dfa->no_of_states) {
                return false;
            }
            new_dfa->transitions[i*new_dfa->no_of_input_alphabets+j] = create_transition(current_state, current_input, next_state);
        }
    }
    return true;
}

dfa* create_dfa() {
    dfa* new_dfa = (dfa*)malloc(sizeof(dfa));
    if (!new_dfa) {
        printf("Memory allocation failed.\n");
        return NULL;
    }

    new_dfa->transitions = NULL;
    new_dfa->input_alphabet = NULL;
    new_dfa->final_states = NULL;

    if (!input_no_of_states(new_dfa)) {
        printf("Number of states should be > 0.\n");
        free_dfa(new_dfa);
        return NULL;
    }

    if (!input_no_of_input_alphabets(new_dfa)) {
        printf("Number of input alphabets should be > 0.\n");
        free_dfa(new_dfa);
        return NULL;
    }

    new_dfa->input_alphabet = (char*)malloc(new_dfa->no_of_input_alphabets * sizeof(char));
    if(!input_input_alphabet(new_dfa)){
        printf("Input only alphanumeric character.\n");
        free_dfa(new_dfa);
        return NULL;
    }

    if (!input_starting_state(new_dfa)) {
        printf("Invalid starting state.\n");
        free_dfa(new_dfa);
        return NULL;
    }

    if (!input_no_of_final_states(new_dfa)) {
        printf("Number of final states should be > 0.\n");
        free_dfa(new_dfa);
        return NULL;
    }

    new_dfa->final_states = (int*)malloc(new_dfa->no_of_final_states * sizeof(int));
    if (!input_final_states(new_dfa)) {
        printf("Invalid final state.\n");
        free_dfa(new_dfa);
        return NULL;
    }

    int no_of_transitions = new_dfa->no_of_input_alphabets*new_dfa->no_of_states;
    new_dfa->transitions = (transition**)malloc(no_of_transitions * sizeof(transition*));
    if (!input_transitions(new_dfa)) {
        printf("Invalid transition states.\n");
        free_dfa(new_dfa);
        return NULL;
    }

    return new_dfa;
}

void display_menu() {
    printf("\n----- DFA Menu -----\n");
    printf("1. Create DFA\n");
    printf("2. Test String\n");
    printf("3. Exit\n");
    printf("--------------------\n");
    printf("Enter your choice: ");
}

int main(int argc, char** argv) {
    dfa* new_dfa = NULL;
    int choice;

    while (1) {
        display_menu();
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1:
                if (new_dfa != NULL) {
                    printf("A DFA already exists. Overwriting it...\n");
                    free_dfa(new_dfa);
                }
                new_dfa = create_dfa();
                if (new_dfa) {
                    printf("DFA created successfully!\n");
                } else {
                    printf("Failed to create DFA.\n");
                }
                break;

            case 2:
                if (new_dfa == NULL) {
                    printf("No DFA exists. Please create a DFA first.\n");
                } else {
                    char input[100];
                    printf("Enter a string to test: ");
                    scanf("%s", input);
                    bool result = dfa_driver(new_dfa, input, new_dfa->starting_state);
                    if (result) {
                        printf("The string is accepted by the DFA.\n");
                    } else {
                        printf("The string is rejected by the DFA.\n");
                    }
                }
                break;

            case 3:
                printf("Exiting program.\n");
                if (new_dfa != NULL) {
                    free_dfa(new_dfa);
                }
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}