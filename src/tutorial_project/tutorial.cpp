#include    <iostream>
#include    <stdio.h>
#include    <math.h>
#include    <vector>

#include    "tutorial_project_config.h"

int main( int argc , char *argv[] )
{
    printf("data of tutorial_project_VERSION_MAJOR : %d\n" , tutorial_project_VERSION_MAJOR );
    printf("data of tutorial_project_VERSION_MINOR : %d\n\n" , tutorial_project_VERSION_MINOR );
    std::vector< unsigned char > buffer;
    buffer.reserve( 100 );
    for( int run = 0 ; run < 15 ; run++ )
    {
        buffer.push_back( run );
    }
    
    printf("size member     : %ld\n" , buffer.size() );
    printf("capacity buffer : %ld\n" , buffer.capacity() );
    printf("max size buffer : %d\n" , buffer.max_size() );

    return 0;
}
