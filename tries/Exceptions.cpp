//
// Created by linux on 9/2/16.
//

#include "Exceptions.h"

const char *altrusian::Tries::PrefixNotFoundException::what() const throw(){
    return "prefix not found";
}
