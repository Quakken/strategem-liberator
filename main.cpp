#include <iostream>
#include <string>

//----- Function Prototypes -----//
void PrintTitle();

//----- Main -----//
int main(int argc, const char** argv) {
    // Print title
    PrintTitle();

    std::getc(stdin);
    return 0;
}

//----- Output Functions -----//

// Prints the title & subtitle to the console
void PrintTitle(){
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