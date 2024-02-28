#include <iostream>

// Directional inputs
const char UP = 'w';
const char DOWN = 's';
const char LEFT = 'a';
const char RIGHT = 'd';
const char END = '\0';

// Strategem declaration
class Strategem
{
private:
    const char * name; // The name of the strategem
    const char * inputs; // The inputs that the strategem takes. Note that it MUST end in a null char or 'END'
public:
    Strategem(const char * name, const char * inputs);
    void print();
    const char * get_inputs();
};
