#include <iostream>
#include <string>
#include "Maple_string.h"

#ifndef Maple_operator_H
#define Maple_operator_H

template <class O>

friend Character operator + (O &ch, O &It);
friend Character operator - (O &ch, O &It);

#endif