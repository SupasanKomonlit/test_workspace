#include    <PushInVector.hpp>

#include    <iostream>
#include    <vector>

#include    <stdio.h>

#include    <import_project_configure.hpp>

int main( int argv , char* argc[] )
{
    std::cout << "dir " << TUTORIAL_PROJECT_DIR_ << "\n";
    std::vector<unsigned char> buffer;
    buffer.reserve( 100 );
    push_data( &buffer , 1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 10 , 11 , 12 , 13 );
    std::cout << "data in buffer :";
    for( int run = 0 ; run < buffer.size() ; run++ )
    {
        printf(" %02x" , buffer[run]);
    }
    std::cout << "\n";

    return 0;
}
