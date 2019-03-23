// FILE         : example_code.cpp
// AUTHOR       : Supasan Komonlit
// CREATE ON    : 2019, MARCH 3

// we test this file in real situation use vector to make a buffer or data for communication

#include    <iostream>
#include    <stdio.h>

#include    <vector>

template< typename single_type >
void push_data( std::vector< single_type >* buffer , single_type data )
{
    (*buffer).push_back( data );
}

template< typename single_type , typename... pack_type>
void push_data( std::vector< single_type >* buffer , single_type first_data 
        , pack_type... other_data )
{
    (*buffer).push_back( first_data );
    push_data( buffer , other_data... );
}

int main()
{
    std::vector< unsigned char > buffer;
    push_data( &buffer , (unsigned char)0xff , (unsigned char)0xaa , (unsigned char)0x10 
            , (unsigned char)0x5 , (unsigned char)0x89 );
    printf( "Your buffer have length is %ld\n" , buffer.size() );
    for( int run = 0 ; run < buffer.size() ; run++ )
    {
        printf( "buffer[%d] = %x\n" , run , buffer[run] );
    }
}
