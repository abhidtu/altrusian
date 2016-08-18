//
// Created by linux on 9/2/16.
//

#include <iostream>

#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H
using namespace std;

namespace LibAlDs {
    namespace Tries {

        class PrefixNotFoundException : public exception {

        public:
            virtual const char* what() const throw();

        };

    }

}


#endif //EXCEPTIONS_H
