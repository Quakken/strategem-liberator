#include <iostream>
#include <string.h>
#include "strategem.h"
#include "main.h"

// Called when a strategem is initialized
Strategem::Strategem(const char * _name, const char * _inputs)
{
    name = _name; // Copy name
    inputs = _inputs; // Copy inputs
}

// Prints the strategem name & inputs to the console
void Strategem::print(){
    std::string formattedName; // Format the name so that it looks all nice and pretty
    formattedName.append("-----===< ").append(name).append(" >===-----");
    center_text(formattedName.c_str(), SCREEN_WIDTH); // Print name

    std::string formattedInputs; // Format the inputs really fancily
    formattedInputs.append("-{ ");
    for (int i = 0; i < strlen(inputs); i++){
        switch (inputs[i]){
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
    formattedInputs.append(" }-");

    center_text(formattedInputs.c_str(), SCREEN_WIDTH); // Print inputs
}
