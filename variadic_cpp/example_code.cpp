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
    return v;
}

template<typename T , typename... Args >
T adder( T first, Args... argc )
{
    printf("function 2 parmeter\n");
    return first + adder( argc... );
}

int main()
{
    int answer = adder( 1 , 2 , 3 , 4 );
    printf( "Last answer is %d\n" , answer );
}
