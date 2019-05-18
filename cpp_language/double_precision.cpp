// FILE			: double_precision.cpp
// AUTHOR		: K.Supasan
// CREATE ON	: 2019, May 18 (UTC+0)
// MAINTAINER	: K.Supasan

// MACRO DETAIL

// README

// REFERENCE
//  ref1    : https://en.cppreference.com/w/cpp/thread/sleep_for
//  ref2    : https://en.cppreference.com/w/cpp/chrono/duration

// MACRO SET

#include    <iostream>

#include    <thread>

int main( int argv , char** argc)
{
    double pi_test = 3.14;

    for(unsigned int round = 0  ;  ; round++ )
    {
        pi_test *= 1;
        if( pi_test == 3.14 )
        {
            std::cout   << "round is " << round << std::endl;
        }
        else
        {
            break;
        }
        std::this_thread::sleep_for( std::chrono::seconds( 1 ) );
    }
}
