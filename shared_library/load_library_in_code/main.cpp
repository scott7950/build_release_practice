#include <iostream>
#include <dlfcn.h>
#include "shared_lib1.h"

int main(int argc, char* argv[]) {
    void *lib_handle;

    lib_handle = dlopen("lib/libshared_lib.so", RTLD_LAZY);
    if(!lib_handle) {
        std::cerr << dlerror() << std::endl;
        return 1;
    }

    char *error;
    void (*fn)();
    *(void **) (&fn) = dlsym(lib_handle, "display1");
    if((error = dlerror()) != NULL) {
        std::cerr << error << std::endl;
        return 1;
    }

    std::cout << "*** In Main ***" << std::endl;
    (*fn)();

    dlclose(lib_handle);

    return 0;
}

