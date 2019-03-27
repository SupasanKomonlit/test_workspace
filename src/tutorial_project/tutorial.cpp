#include    <iostream>
#include    <stdio.h>
#include    <math.h>
#include    <vector>

#include    <tutorial_project_config_binary.h>
#include    <PushInVector/push_data.cpp>

int main( int argc , char *argv[] )
{
    printf("data of tutorial_project_VERSION_MAJOR : %d\n" , tutorial_project_VERSION_MAJOR );
    printf("data of tutorial_project_VERSION_MINOR : %d\n\n" , tutorial_project_VERSION_MINOR );
    std::vector< unsigned char > buffer;
    buffer.reserve( 100 );

    push_data( &buffer , 1 , 2 , 3 , 4 , 5 , 6 , 7 , 8);
    
    printf("size member     : %ld\n" , buffer.size() );
    printf("capacity buffer : %ld\n" , buffer.capacity() );
    printf("max size buffer : %d\n" , buffer.max_size() );

    return 0;
}
