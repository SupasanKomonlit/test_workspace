// FILE         : template_typename.cpp
// AUTHOR       : Supasan Komonlit
// CREATE ON    : 2019, APRIL 20

#include    <iostream>

namespace group_01
{
    class class_01{
        int number;
        public:
            class_01( int number )
            {
                this->number = number;
            }

            void print()
            {
                std::cout << "class_01 number is " << this->number << "\n";
            }
    };

    class class_02{
        int number;
        public:
            class_02( int number )
            {
                this->number = number;
            }

            void print()
            {
                std::cout << "class_02 number is " << this->number << "\n";
            }
    };
}

void all_print( group_num::class_01 first_class , group_num::class_02 second_class )
{
    first_class.print();
    second_class.print();
}

int main()
{
    group_01::class_01 first_class( 10 );
    group_01::class_02 second_class( 20 );
}
