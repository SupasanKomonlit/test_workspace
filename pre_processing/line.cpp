// FILE         : line.cpp
// AUTHOR       : Supasan Komonlit
// CREATE ON    : 2019, APRIL 20

#include    <iostream>

void test_function()
{
    std::cout << "Line by function " << __LINE__ << "\n"; 
}

void test_function( unsigned int line_number )
{
    std::cout << "Pass parameter " << line_number << "\n";
}

int main()
{
    std::cout << __LINE__ << "\n";
    test_function();
    test_function(__LINE__);
} // function main
