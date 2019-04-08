// File         : char_to_string.cpp
// Author       : Supasan Komonlit
// Create on    : 2019, APRIL 9 

#include    <iostream>

int main()
{
    std::string message = ":BSI asdqwd aiai";
    std::string temp = "";
    temp.push_back( message[0] );
    temp.push_back( message[1] );
    std::cout << "temp is " << temp << std::endl;

} // main
