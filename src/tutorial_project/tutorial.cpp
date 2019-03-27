#include    <iostream>
#include    <stdio.h>
#include    <math.h>
#include    <vector>

int main( int argc , char *argv[] )
{
    std::vector< unsigned char > buffer;
    buffer.reserve( 100 );
    for( int run = 0 ; run < 10 ; run++ )
    {
        buffer.push_back( run );
    }
    
    printf("size member     : %ld\n" , buffer.size() );
    printf("capacity buffer : %ld\n" , buffer.capacity() );
    printf("max size buffer : %ld\n" , buffer.max_size() );

    return 0;
}
