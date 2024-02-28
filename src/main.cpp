#include <iostream> // input/output (getc, cout, etc.)
#include <stdlib.h> // system("clear")
#include <string> // std::string
#include <cstring> // strlen
#include <vector> // vectors
#include <conio.h> // getch
#include <windows.h> // chcp
#include <time.h> // timer
#include "strategem.h"
#include "main.h"

//----- Global Variables -----//
const int SCREEN_WIDTH = 87; // Width of the screen in characters
const int ROUND_LENGTH = 15; // Length of a round
const int COMPLETION_BONUS = 2; // How much time you gain for completing an input
std::vector<Strategem> strategems;

//----- Non-Global Function Prototypes -----//
void print_strat(Strategem * strat, bool printTitle = false);
void print_score(int score);

//----- Main -----//
int main(int argc, const char** argv) {
    // Initialize the console
    SetConsoleOutputCP(65001);

    // Set the seed
    srand(time(NULL));

    // Initialize strategems
    initialize_strategems();

    // Main loop
    while (1){
        // Clear the screen
        system("cls");

        // Print title
        print_title();

        // Choose a random strategem
        Strategem * strat = &strategems[rand() % strategems.size()];

        // Print it
        strat->print();

        // Initialize timer
        time_t startTime = time(NULL);
        time_t timer = ROUND_LENGTH;

        // Store the current input of the strategem
        int currentIn = 0;

        // Store the current round
        int currentRound = 0;
        
        // Loop until the timer runs out
        while (timer > 0){
            // Update the timer with the current time
            timer = ROUND_LENGTH + (currentRound * COMPLETION_BONUS) - difftime(time(NULL), startTime);
            printf("%*s--=#>%*s<#=-- \r", (SCREEN_WIDTH - timer - strlen("--=#>") * 2) / 2, "", timer, "");

            // Get user input
            if (kbhit()){
                char input = getch();

                // Compare user input to the current input
                if (input == strat->get_inputs()[currentIn]){
                    // If it matches, move on to the next one
                    currentIn++;
                    std::string formattedInputs; // Format the inputs really fancily
                    formattedInputs.append("-< ");
                    for (int i = 0; i < currentIn; i++){
                        switch (strat->get_inputs()[i]){
                            case UP:
                                formattedInputs.append(" ↑ ");
                                break;
                            case DOWN:
                                formattedInputs.append(" ↓ ");
                                break;
                            case LEFT:
                                formattedInputs.append(" ← ");
                                break;
                            case RIGHT:
                                formattedInputs.append(" → ");
                                break;
                        }
                    }
                    formattedInputs.append(" >-");
                    center_text(formattedInputs.c_str(), SCREEN_WIDTH, strlen("-< ") * 2 + strlen(strat->get_inputs()) * 3);

                    // See if the final input was inputted
                    if (strat->get_inputs()[currentIn] == END){
                        // If it was, get a new input & increase the timer
                        currentRound++;

                        strat = &strategems[rand() % strategems.size()];
                        print_strat(strat, true);
                    }
                }
                else {
                    // If the player fails, reset the current input and have them keep trying
                    currentIn = 0;
                    print_strat(strat, true);
                }
            }
        }

        print_score(currentRound);
        getchar();
    }
    return 0;
}

//----- Initialization Functions -----//

// Initializes all strategems
void initialize_strategems(){
    strategems.push_back(Strategem("NUX-223 Hellbomb", new const char[7] {UP, LEFT, RIGHT, DOWN, UP, DOWN, END}));
    strategems.push_back(Strategem("AC-8 Autocannon", new const char[7] {DOWN, LEFT, DOWN, UP, UP, RIGHT, END}));
    strategems.push_back(Strategem("Eagle 500kg Bomb", new const char[6] {UP, RIGHT, DOWN, DOWN, DOWN, END}));
    strategems.push_back(Strategem("EAT-17 Expendable Anti-Tank", new const char[6] {DOWN, LEFT, RIGHT, UP, DOWN, END}));
    strategems.push_back(Strategem("FAF-14 Spear", new const char[7] {DOWN, LEFT, DOWN, UP, UP, RIGHT, END}));
    strategems.push_back(Strategem("FLAM-40 'Incinerator' Flamethrower", new const char[6] {DOWN, LEFT, DOWN, RIGHT, LEFT, END}));
    strategems.push_back(Strategem("LAS-98 Laser Cannon", new const char[6] {DOWN, LEFT, DOWN, UP, LEFT, END}));
    strategems.push_back(Strategem("LIFT-850 Jump Pack", new const char[6] {DOWN, UP, UP, DOWN, UP, END}));
    strategems.push_back(Strategem("MG-43 Machine Gun", new const char[6] {DOWN, LEFT, DOWN, UP, RIGHT, END}));
    strategems.push_back(Strategem("Reinforce", new const char[6] {UP, DOWN, RIGHT, LEFT, UP, END}));
    strategems.push_back(Strategem("Resupply", new const char[5] {DOWN, DOWN, UP, RIGHT, END}));
    strategems.push_back(Strategem("B-1 Supply Pack (Resupply Pack)", new const char[6] {DOWN, UP, DOWN, DOWN, RIGHT, END}));
    strategems.push_back(Strategem("RS-422 Railgun", new const char[7] {DOWN, RIGHT, DOWN, UP, LEFT, RIGHT, END}));
}

//----- Output Functions -----//

// Prints the title & subtitle to the console
void print_title(){
    std::cout << " ___         _____  _____ ______   ___  _____  _____  _____  _____ ___  ___        ___ " << std::endl
            << "|  _|       /  ___||_   _|| ___ \\ / _ \\|_   _||  ___||  __ \\|  ___||  \\/  |       |_  |" << std::endl
            << "| | ______  \\ `--.   | |  | |_/ // /_\\ \\ | |  | |__  | |  \\/| |__  | .  . |  ______ | |" << std::endl
            << "| ||______|  `--. \\  | |  |    / |  _  | | |  |  __| | | __ |  __| | |\\/| | |______|| |" << std::endl
            << "| |         /\\__/ /  | |  | |\\ \\ | | | | | |  | |___ | |_\\ \\| |___ | |  | |         | |" << std::endl
            << "| |_        \\____/   \\_/  \\_| \\_|\\_| |_/ \\_/  \\____/  \\____/\\____/ \\_|  |_/        _| |" << std::endl
            << "|___|                                                                             |___|" << std::endl
            << "                                                                                       " << std::endl
            << "              _     _____ ______  _____ ______   ___  _____  _____ ______              " << std::endl
            << " ______      | |   |_   _|| ___ \\|  ___|| ___ \\ / _ \\|_   _||  _  || ___ \\      ______ " << std::endl
            << "|______|     | |     | |  | |_/ /| |__  | |_/ // /_\\ \\ | |  | | | || |_/ /     |______|" << std::endl
            << " ______      | |     | |  | ___ \\|  __| |    / |  _  | | |  | | | ||    /       ______ " << std::endl
            << "|______|     | |_____| |_ | |_/ /| |___ | |\\ \\ | | | | | |  \\ \\_/ /| |\\ \\      |______|" << std::endl
            << "             \\_____/\\___/ \\____/ \\____/ \\_| \\_|\\_| |_/ \\_/   \\___/ \\_| \\_|             " << std::endl
            << std::endl;
    center_text("by Quakken", SCREEN_WIDTH);
    std::cout << std::endl;
}

void print_score(int score){
    system("cls");
    std::cout << "                      __  _____   ___  ___  ___ _____   _____  _   _ ___________  __                      " << std::endl 
              << "       ______ ______ / / |  __ \\ / _ \\ |  \\/  ||  ___| |  _  || | | |  ___| ___ \\ \\ \\ ______ ______       " << std::endl 
              << " _____|______|______/ /  | |  \\// /_\\ \\| .  . || |__   | | | || | | | |__ | |_/ /  \\ \\______|______|_____ " << std::endl 
              << "|______|_____ _____< <   | | __ |  _  || |\\/| ||  __|  | | | || | | |  __||    /    > >_____ _____|______|" << std::endl
              << "      |______|______\\ \\  | |_\\ \\| | | || |  | || |___  \\ \\_/ /\\ \\_/ / |___| |\\ \\   / /______|______|      " << std::endl
              << "                     \\_\\  \\____/\\_| |_/\\_|  |_/\\____/   \\___/  \\___/\\____/\\_| \\_| /_/                     " << std::endl
              << std::endl;
    center_text("-==< Final Score >==-", 116);
    center_text(std::to_string(score).c_str(), 116);
}

// Prints a strategem to the console
void print_strat(Strategem * strat, bool printTitle){
    if (printTitle){
        system("cls");
        print_title();
    }

    strat->print();
}

// Prints the given text centered
void center_text(const char * text, int fieldWidth, int lengthOverride) {
    int padlen = (fieldWidth - ((lengthOverride == 0) ? strlen(text) : lengthOverride)) / 2;
    printf("%*s%s%*s\n", padlen, "", text, padlen, "");
} 