// FILE         : example_code.cpp
// AUTHOR       : Supasan Komonlit
// CREATE ON    : 2019, MARCH 3

// we test this file in real situation use vector to make a buffer or data for communication

#include    <iostream>
#include    <stdio.h>

#include    <vector>

void push_data( std::vector< unsigned char >* buffer , unsigned char data )
{
    (*buffer).push_back( data );
}

void push_data( std::vector< unsigned char >* buffer , unsigned char first_data 
        , unsigned char... other_data )
{
    (*buffer).push_back( first_data );
    push_back( buffer , other_data... );
}

int main()
{
    std::vector< unsigned char > buffer;
    push_data( &buffer , 0xff , 0xaa , 0x10 , 0x5 , 0x89 );
    printf( "Your buffer have length is %d\n" , buffer.size() );
    for( int run = 0 ; run < buffer.size() ; run++ )
    {
        printf( "buffer[%d] = %x\n" , run , buffer[run] );
    }
}
