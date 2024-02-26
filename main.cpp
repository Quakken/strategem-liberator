#include <iostream> // input/output (getc, cout, etc.)
#include <string> // std::string
#include <vector> // vectors
#include <conio.h> // getch
#include "strategem.h"

//----- Global Variables -----//
std::vector<Strategem> strategems;

//----- Function Prototypes -----//
void initialize_strategems();
void print_title();

//----- Main -----//
int main(int argc, const char** argv) {
    // Initialize strategems
    initialize_strategems();

    // Print title
    print_title();

    // Choose a random strategem
    Strategem * strat = &strategems[rand() % strategems.size()];

    strat->print();

    // Main loop
    while (1){
        
        // Get user input
        if (kbhit()){
            char input = getch();
        }
    }
    return 0;
}

//----- Initialization Functions -----//

// Initializes all strategems
void initialize_strategems(){
    strategems.push_back(Strategem("NUX-223 Hellbomb", new const char[7] {UP, LEFT, RIGHT, DOWN, UP, DOWN, END}));
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
            << std::endl
            << "                            -- ported to c++ by Quakken --" << std::endl;
}


