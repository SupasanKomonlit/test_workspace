// FILE         : clear_screen.cpp
// AUTHOR       : Supasan Komonlit
// DATE ON      : 2019, APRIL 05

#include    <iostream>

int main( int argv , char** argc )
{

    std::cout << "std::cout before try to erase disply\n";
    std::cout << "\x1B[1J"; // this different about clear command
    std::cout << "\x1B[H";
//    std::cout << "After use erase display escape sequences\n";

} // main
