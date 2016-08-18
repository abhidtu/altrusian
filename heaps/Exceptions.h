//
// Created by linux on 3/2/16.
//

#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H
#include <iostream>
#include <exception>

using namespace std;

namespace LibAlDs {

    namespace Heaps {

        class EmptyHeapException: public exception {

        public:
            virtual const char* what() const throw();

        };

        class IndexOutOfBounds: public exception {

        public:
            virtual const char* what() const throw();

        };

    }

}


#endif //EXCEPTIONS_H
