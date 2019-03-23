// FILE         : example_code.cpp
// AUTHOR       : Supasan Komonlit
// CREATE ON    : 2019, MARCH 3

// This file I follow code and edit from reference website
//      reference   : https://eli.thegreenplace.net/2014/variadic-templates-in-c/

#include    <iostream>
#include    <stdio.h>

template<typename T> 
T adder(T v)
{
    printf("function 1 parameter\n");
    std::cout << __PRETTY_FUNCTION__ << "\n"; // you can use this to show about all parameter
    return v;
}

template<typename T , typename... Args >
T adder( T first, Args... argc )
{
    printf("function 2 parmeter have number of argument is %d\n" , first );
    std::cout << __PRETTY_FUNCTION__ << "\n"; // you can use this to show about all parameter
    return first + adder( argc... );
}

int main()
{
    int answer = adder( 5 , 4 , 2 , 1 , 3);
    printf( "Last answer is %d\n" , answer );
}
