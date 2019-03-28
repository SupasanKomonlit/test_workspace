#include    <iostream>
#include    <vector>

template<typename buffer_type , typename single_type>
void push_data( std::vector<buffer_type>* buffer , single_type data )
{
    buffer->push_back( (buffer_type) data );
}

template<typename buffer_type , typename single_type , typename... pack_type>
void push_data( std::vector<buffer_type>* buffer , single_type data , pack_type... pack_data )
{
    push_data( buffer , data );
    push_data( buffer , pack_data... );
}
