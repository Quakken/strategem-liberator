#include <iostream>
#include "strategem.h"

// Called when a strategem is initialized
Strategem::Strategem(const char * _name, const char * _inputs)
{
    name = _name; // Copy name
    inputs = _inputs; // Copy inputs
}

// Prints the strategem name & inputs to the console
void Strategem::print(){
    std::cout << name << std::endl;
    std::cout << inputs << std::endl;
}
