#include    <iostream>
#include    <vector>

template<typename buffer_type , typename single_type>
void push_data( std::vector<buffer_type>* buffer , single_type data );

template<typename buffer_type , typename single_type , typename... pack_type>
void push_data( std::vector<buffer_type>* buffer , single_type data , pack_type... pack_data );
