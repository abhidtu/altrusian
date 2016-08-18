//
// Created by linux on 3/2/16.
//

#include "Exceptions.h"

#include <iostream>
#include <exception>

using namespace std;

namespace LibAlDs {

    const char *Heaps::EmptyHeapException::what() const throw() {
        return "trying to access element from empty Heap";
    }

    const char *Heaps::IndexOutOfBounds::what() const throw(){
        return "trying to update index out of bounds";
    }

}
