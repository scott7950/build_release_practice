#include <iostream>
#include "static_lib1.h"
#include "static_lib2.h"

void display1() {
    std::cout << "*** In Static Lib 1 ***" << std::endl;
    display2();
}

