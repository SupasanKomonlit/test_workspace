// FILE			: size_array.cpp
// AUTHOR		: K.Supasan
// CREATE ON	: 2019, May 15 (UTC+0)
// MAINTAINER	: K.Supasan

// MACRO DETAIL

// README

// REFERENCE

// MACRO SET

#include    <iostream>

template< typename type_array >
void know_size( type_array array[] )
{
    std::cout   << "Size of array is " << sizeof( array ) << "\n";
}

template< typename type_array >
void size_type( type_array array )
{
    std::cout   << "Size of type is " << sizeof( array ) << "\n";
}

int main( int argv , char** argc )
{
    double test_double[10];
    int test_integer[20];
    std::cout   << "Outside size is " << sizeof( test_double ) << "\n";
    know_size( test_double );
    std::cout   << "Outside size is " << sizeof( test_integer ) << "\n";
    know_size( test_integer );
    double double_value = 10.00;
    float float_value = 10.00;
    int integer_value = 10.00;
    size_type( double_value );
    size_type( float_value );
    size_type( integer_value );
}
