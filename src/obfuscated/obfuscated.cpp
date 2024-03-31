#include <iostream>
#include <dlfcn.h>

// Define function signatures
typedef void (*FunctionPtr)();

extern "C" {

// Function implementations
void first() {
    std::cout << "First function\n";
}

void second() {
    std::cout << "Second function\n";
}

void third() {
    std::cout << "Third function\n";
}

}

int main() {
    // Load the dynamic library
    void* handle = dlopen(NULL, RTLD_LAZY);

    if (!handle) {
        std::cerr << "Failed to load dynamic library: " << dlerror() << std::endl;
        return 1;
    }

    // Resolve the obfuscated functions
    FunctionPtr firstFunc = reinterpret_cast<FunctionPtr>(dlsym(handle, "first"));
    FunctionPtr secondFunc = reinterpret_cast<FunctionPtr>(dlsym(handle, "second"));
    FunctionPtr thirdFunc = reinterpret_cast<FunctionPtr>(dlsym(handle, "third"));

    if (!firstFunc || !secondFunc || !thirdFunc) {
        std::cerr << "Failed to resolve obfuscated functions: " << dlerror() << std::endl;
        dlclose(handle);
        return 1;
    }

    // Call each obfuscated function indirectly
    firstFunc();
    secondFunc();
    thirdFunc();

    // Close the dynamic library
    dlclose(handle);

    return 0;
}
