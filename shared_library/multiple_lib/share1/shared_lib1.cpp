#include <iostream>
#include "shared_lib1.h"
#include "shared_lib2.h"

void display1() {
    std::cout << "*** In Shared Lib 1 ***" << std::endl;
    display2();
}

